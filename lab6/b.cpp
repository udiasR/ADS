#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
typedef long long ll;
using namespace std;

void merge(vector<int>&v, int l, int m , int r){
    int n1 = m - l +1;
    int n2 = r - m;
    vector<int>L(n1);
    vector<int>R(n2);

    for(int i = 0; i < n1;i++)L[i] = v[l+i];
    for(int j = 0; j < n2;j++)R[j] = v[m+1+j];

    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            v[k] = L[i];
            i++;
            k++;
        } else{
            v[k] = R[j];
            j++;
            k++;
        }
    }

    while( i < n1){
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

        mergeSort(v, l, m);
        mergeSort(v, m+1, r);
        merge(v, l, m, r);
    }
}

int main(){
    int a,b;
    cin >> a>> b;
    vector<int>v1(a);
    vector<int>v2(b);
    for(int i = 0; i < a;i++)cin >> v1[i];
    for(int i = 0; i < b;i++)cin >> v2[i];
    mergeSort(v1, 0, a-1);
    mergeSort(v2, 0, b-1);

    int i = 0, j = 0;
    while(i < a && j < b){
        if(v1[i] == v2[j]) {
            cout << v1[i] << ' ';
            i++;
            j++;
        } else if(v1[i] < v2[j]) {
            i++;  
        } else {
            j++; 
        }
    }
}