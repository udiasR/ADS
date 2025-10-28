#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

void merge(vector<int>&v, int l, int m , int r){
    int n1 = m-l+1;
    int n2  = r-m;

    vector<int>L(n1);
    vector<int>R(n2);

    for(int i = 0; i < n1;i++)L[i] = v[l+i];
    for(int i = 0; i < n2;i++)R[i] = v[i+m+1];


    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            v[k] = L[i];
            k++;
            i++;
        } else{
            v[k]= R[j];
            j++;
            k++;
        }
    }

    while(i < n1){
        v[k] = L[i];
        k++;
        i++;
    }

    while(j < n2){
        v[k] = R[j];
        k++;
        j++;
    }

}


void mergeSort(vector<int>&v, int l, int r){
    if(l < r){
        ll m = (l+r)/2;
        mergeSort(v, l, m);
        mergeSort(v,m+1,r);

        merge(v,l,m,r);
    }
}


int main(){
    int n,s;
    cin >> n;
    vector<int>v(n);

    for(int i = 0; i < n;i++)cin >> v[i];
    cin >> s;
    for(int i = 0; i < s;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    mergeSort(v, 0, v.size()-1);

    for(int i = 0; i < v.size();i++){
        cout << v[i] << " ";
    }

    cout << '\n';

    
}