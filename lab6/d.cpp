#include <iostream>
#include <cmath>
#include <climits>
#include <iomanip>
#include <vector>
typedef long long ll;
using namespace std;

struct date{
    int day;
    int month;
    int year;
};

void merge(vector<date>&v, int l, int m, int r){
    int n1  = m-l+1;
    int n2 = r-m;
    vector<date>L(n1);
    vector<date>R(n2);

    for(int i = 0; i < n1;i++)L[i] = v[l+i];
    for(int i = 0; i < n2;i++)R[i] = v[m+1+i];

    int i =0,  j = 0;
    int k = l;
    while(i < n1 && j < n2){
        if(L[i].year < R[j].year){
            v[k] = L[i];
            i++;
            k++;
        } else if(L[i].year > R[j].year){
            v[k] = R[j];
            j++;
            k++;
        } else{
            if(L[i].month < R[j].month){
                v[k] = L[i];
                i++;
                k++;
            } else if(L[i].month > R[j].month){
                v[k] = R[j];
                j++;
                k++;
            } else{
                if(L[i].day < R[j].day){
                    v[k] = L[i];
                    i++;
                    k++;
                } else {
                    v[k] = R[j];
                    j++;
                    k++;
                }
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

void mergeSort(vector<date>&v, int l, int r){
    if(l < r){
        int m = (l+r)/2;

        mergeSort(v,l,m);
        mergeSort(v,m+1,r);
        merge(v,l,m,r);
    }

}

int main(){
    int n;
    cin >> n;
    vector<date>v(n);
    for(int i = 0; i < n;i++){
        string s;
        cin >> s;
        v[i].day = (s[0] - '0')* 10 + (s[1] - '0');
        v[i].month = (s[3] - '0') * 10 + (s[4] - '0');
        v[i].year = (s[6] - '0') * 1000 + (s[7] - '0') * 100 + (s[8] - '0') * 10 + (s[9] - '0');
    }

    mergeSort(v, 0, n-1);
    for(int i = 0; i < n;i++){
        if(v[i].day / 10 == 0)cout << 0;
        cout << v[i].day << '-' ;
        if(v[i].month / 10 == 0)cout << 0;
        cout << v[i].month << '-' << v[i].year << '\n';
    }

}