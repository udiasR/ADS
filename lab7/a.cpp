#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

void merge(vector<string>&v, int l, int m, int r){
    int n1 = m-l+1;
    int n2 =r-m;

    vector<string>L(n1), R(n2);
    for(int i = 0; i < n1;i++)L[i] = v[i+l];
    for(int j = 0; j < n2;j++)R[j] = v[m+j+1];


    int i = 0;
    int j = 0;
    int k = l;
    while(i < n1 && j < n2){
        if(L[i].size() < R[j].size()){
            v[k] = L[i];
            k++;
            i++;
        } else if(L[i].size() > R[j].size()){
            v[k] = R[j];
            j++;
            k++;
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


void mergeSort(vector<string>&v, int l, int r){
    if(l < r){
        int m = (l+r)/2;
        mergeSort(v, l, m);
        mergeSort(v, m+1, r);

        merge(v, l, m, r);
    }
}

int main(){
   int t;
   cin >> t;
   cin.ignore();
    while(t--){
        string s;
        vector<string>v;

        getline(cin,s);
        stringstream ss(s);
        while(ss >> s)v.push_back(s);
        mergeSort(v, 0, v.size()-1);
        for(int i = 0; i < v.size();i++){
            cout << v[i] << " ";
        }
        cout << '\n';
    }
}