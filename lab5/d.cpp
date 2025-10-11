#include <iostream>

#include<queue>
using namespace std;

int main(){
    int n,m,in;
    cin >> n >> m;
    priority_queue<int,vector<int>, greater<int>>pq;
    for(int i = 0; i < n;i++){
        cin >> in;
        pq.push(in);
    }   
    int cnt = 0;

    while(pq.top() <= m){
        if(pq.size() == 1 && pq.top() < m){
            cout << -1;
            return 0;
        }
        int newest = pq.top();
        pq.pop();
        newest += 2 * pq.top();
        pq.pop();
        pq.push(newest);
        cnt++;
    }

    cout << cnt;

    
}