#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int main(){
    int n,in;
    cin >> n;
    priority_queue<int>pq;
    for(int i = 0; i < n;i++){
        cin >> in;
        pq.push(in);
    }

    while(pq.size() > 1){
        int y = pq.top();
        pq.pop();
        int x  = pq.top();
        pq.pop();
        if(x == y)continue;
        else {
            y = y-x;
            pq.push(y);
        }
    }
    if(pq.size() == 1)cout << pq.top();
    else cout << 0;

}