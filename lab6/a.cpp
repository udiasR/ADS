#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
typedef long long ll;
using namespace std;

void merge(vector<char>&v, int l , int m , int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<char>L(n1);
    vector<char>R(n2);
    for(int i = 0; i < n1;i++)L[i] = v[l+i];
    for(int i = 0; i < n2;i++)R[i] = v[m+1+i];

    int i = 0; int j = 0; int k = l;
    while(i < n1 && j < n2){
        if(L[i] < R[j]){
            v[k] = L[i];
            i++;
            k++;
        } else {
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

        merge(v, l, m , r);
    }
}


int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<char>vowels;
    vector<char>consonants;

    for(int i = 0; i < s.size();i++){
        if(s[i] == 'a')vowels.push_back(s[i]);
        else if(s[i] == 'e')vowels.push_back(s[i]);
        else if(s[i] == 'i')vowels.push_back(s[i]);
        else if(s[i] == 'o')vowels.push_back(s[i]);
        else if(s[i] == 'u')vowels.push_back(s[i]);
        else consonants.push_back(s[i]);
    }
    mergeSort(vowels, 0, vowels.size()-1);
    mergeSort(consonants, 0, consonants.size()-1);

    for(int i = 0; i < vowels.size();i++)cout << vowels[i];
    for(int i = 0; i < consonants.size();i++)cout << consonants[i];
    




}