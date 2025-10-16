#include <iostream>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n;
    map<string, string>mp;
    for(int i = 0; i < n;i++){
        string s,t;
        cin >> s >> t;
        bool ok = 0;
        for(auto &x : mp){
            if(x.second == s){
                x.second = t;
                ok = 1;
            } 
        }

        if(!ok){
            mp.insert({s,t});
        }
    }

    int size = mp.size();
    cout << size << '\n';
    for(auto x : mp){
        cout << x.first << " " << x.second << "\n";
    }
}