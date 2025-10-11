#include <iostream>
#include <algorithm>
#include <queue>
typedef long long ll;
using namespace std;






int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    ll n,k, in;
    cin >> n >>k;
    priority_queue<ll>pq;
    for(int i = 0; i < n;i++){
        cin >> in;
        pq.push(in);
    }
    ll sum = 0;
    while(k--){
        ll t = pq.top();
        sum+= pq.top();
        pq.pop();
        pq.push(t-1);
    }

    cout << sum;
    


    


}
