#include <iostream>
#include <cmath>
#include <climits>
#include <iomanip>
#include <vector>
typedef long long ll;
using namespace std;


void merge(vector<int>&v, int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r- m;

    vector<int>L(n1);
    vector<int>R(n2);
    for(int i = 0; i < n1;i++)L[i] = v[i+l];
    for(int i = 0; i < n2;i++)R[i] = v[i+m+1];

    int i = 0;
    int j = 0;
    int k = l;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            v[k] = R[j];
            k++;
            j++;
        } else{
            v[k] = L[i];
            i++;
            k++;
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


void mergeSort(vector<int>&v, int l, int r){
    if(l < r){
        int m = (l+r)/2;

        mergeSort(v,l, m);
        mergeSort(v,m+1, r);
        merge(v, l, m,r);
    }

}


int main(){
    int a,b;
    cin >> a >> b;
    int arr[a][b];

    for(int i = 0; i < a;i++){
        for(int j = 0; j < b;j++)cin >> arr[i][j];
    }
    vector<int>v;
    for(int j = 0; j < b; j++) {
        v.clear();
        for(int i = 0; i < a; i++) {
            v.push_back(arr[i][j]);
        }
        mergeSort(v, 0, a - 1);
        for(int i = 0; i < a; i++) {
            arr[i][j] = v[i];
        }
    }
    

    for(int i = 0; i < a;i++){
        for(int j = 0; j < b;j++){
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }

}