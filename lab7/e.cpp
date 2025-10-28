#include <iostream>
#include <vector>
using namespace std;

void merge(vector<pair<int, vector<int>>>&v, int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;

    vector<pair<int, vector<int>>>L(n1), R(n2);
    for(int i = 0; i < n1;i++)L[i] = v[l+i];
    for(int j = 0; j < n2;j++)R[j] = v[j+m+1];

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(L[i].first > R[j].first){
            v[k] = L[i];
            i++;
            k++;
        } else if(L[i].first < R[j].first){
            v[k] = R[j];
            j++;
            k++;
        } else{
            bool found = false;
            for(int k2 = 0; k2 < L[i].second.size() && !found;k2++){
                if(L[i].second[k2] < R[j].second[k2]){
                    v[k] = L[i];
                    i++;
                    k++;
                    found = true;
                } else if(L[i].second[k2] > R[j].second[k2]){
                    v[k] = R[j];
                    j++;
                    k++;
                    found = true;
                }
            }
            if(!found){
                v[k] = R[j];
                j++;
                k++;
            }
        }
    }

    while(i < n1){
        v[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        v[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<pair<int, vector<int>>>&v, int l, int r){
    if(l < r){
        int m = (l+r)/2;

        mergeSort(v, l, m);
        mergeSort(v, m+1, r);

        merge(v, l, m, r);
    }
}

int main(){

    int n, size;
    cin >> n >> size;
    vector<pair<int, vector<int>>>v(n);
    for(int i = 0; i < n;i++){
        int sum  = 0;
        vector<int>temp(size);
        for(int j = 0; j < size;j++){
            cin >> temp[j];
            sum+=temp[j];
        }
        v[i] = {sum, temp};
    }

    mergeSort(v, 0, n-1);
    for(int i = 0; i < n;i++){
        for(int j = 0; j < size;j++){
            cout << v[i].second[j] << " ";
        }
        cout << '\n';
    }

}