#include <iostream>

#include<queue>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(){
    
    ll q,n;
    cin >> q >> n;
    priority_queue<ll, vector<ll>, greater<ll>>pq;
    
    ll sum = 0;
    for(int i = 0; i < q;i++){
        string s;
        cin >> s;
        if(s== "insert"){
            int x;
            cin >> x;
            if(pq.size() == n){
                if(pq.top() < x){
                    ll t =pq.top();
                    sum-=t;
                    pq.pop();
                    pq.push(x);
                    sum += x;
                }
            } else{
                pq.push(x);
                sum+=x;
            }
        } else{
            cout << sum << "\n";
        }
    }

    
}