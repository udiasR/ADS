#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
typedef long long ll;
using namespace std;

void merge(vector<char>&v, int l, int m, int r){
    // if 6 = 3.      m - l
    // if 7 = 3
    int n1 = m - l +1;
    int n2 = r - m;

    vector<char>L(n1);
    vector<char>R(n2);
    for(int i = 0; i < n1;i++){
        L[i] = v[l+i];
    }
    for(int i = 0; i < n2;i++){
        R[i] = v[m+1+i];
    }

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(L[i] < R[j]){
            v[k] = L[i];
            i++;
            k++;
        } else{
            v[k] = R[j];
            j++;
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



void mergeSort(vector<char>&v, int l, int r){
    if(l < r){
        int m = (l+r)/2;

        mergeSort(v, l, m);
        mergeSort(v, m+1, r);
        merge(v,l,m,r);
    }
}



int main(){
    string s;
    cin >> s;
    vector<char>v(s.size());
    for(int i = 0; i < s.size();i++)v[i] = s[i];

    mergeSort(v, 0, s.size()-1);

    for(int i = 0; i < s.size();i++)cout << v[i];
    return 0;
}