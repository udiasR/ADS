#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
typedef long long ll;
using namespace std;

int partition(vector<int>&v, int l, int r){
    int pivot = v[l];
    int i = l+1;
    int j = r;

    while(i <= j){
        while(i <= r && pivot >= v[i])i++;
        while(j > l && pivot < v[j])j--;

        if(i < j)swap(v[i], v[j]);
    }

    swap(v[l], v[j]);
    return j;
}


void quickSort(vector<int>&v, int l, int r){
    if(l < r){
        int pivot = partition(v, l, r);;

        quickSort(v, l, pivot-1);
        quickSort(v, pivot+1, r);
        
    }
}

int main(){
    
    int n;
    cin >> n;
    vector<int>v(n);
    for(int i = 0; i < n;i++)cin >> v[i];
    quickSort(v, 0, n-1);
    int mindiff = INT_MAX;
    for (int i = 0; i + 1 < n; i++) mindiff = min(mindiff, abs(v[i] - v[i + 1]));
    for (int i = 0; i + 1 < n; i++) {
        if (abs(v[i] - v[i + 1]) == mindiff)
            cout << v[i] << " " << v[i + 1] << " ";
    }

}
