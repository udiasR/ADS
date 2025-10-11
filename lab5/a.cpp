#include <iostream>
#include <algorithm>
#include <queue>
typedef long long ll;
using namespace std;






int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    ll n, in;
    cin >> n;

    priority_queue<ll, vector<ll>, greater<ll>>pq;
    for(int i = 0; i < n;i++){
        cin >> in;
        pq.push(in);
    }
    ll sum = 0;
    while(pq.size() != 1){
        ll t1 = pq.top();
        pq.pop();
        ll t2 = pq.top();
        pq.pop();
        sum+=t1+t2;
        ll newt = t1+t2;
        pq.push(newt);
    }

    cout << sum;


    


}
