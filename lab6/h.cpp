#include <iostream>
#include <cmath>
#include <climits>
#include <vector>
typedef long long ll;
using namespace std;



int main(){
    int n;
    cin >> n;
    vector<char>v(n);
    for(int i = 0; i < n;i++)cin >>v[i];
    char x;
    cin >> x;
    for(int i = 0; i < n;i++){
        if(v[i] > x){
            cout << v[i];
            return 0;
        }
    }

    cout << v[0];
}