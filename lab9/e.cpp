#include <iostream>
#include <vector>
using namespace std;

vector<int>lps(string s){
    int n = s.size();
    int i = 1, len = 0;
    vector<int>lps(n,0);
    while(i < n){
        if(s[i] == s[len]){
            len++;
            lps[i] = len;
            i++;
        } else{
            if(!len)i++;
            else len = lps[len-1];
        }
    }
    return lps;
    
}


int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        int k;
        cin >> s >> k;
        vector<int>olps = lps(s);
        int n = s.size();
        int p = olps[n-1];
        
        long long res = n + (k - 1) * (n - p);
        cout << res << '\n';
    }
}

// asas
// 0012


// mononoke
// 00000000