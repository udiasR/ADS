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
            if(!len) i++;
            else len = lps[len-1];
        }
    }
    return lps;
}



int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> olps = lps(s);

    int cnt = 0;

    for (int L = 1; L * 2 < n; ++L) {
        bool ok = true;
        for (int i = 0; i < L; ++i) {
            if (s[i] != s[L + i]) {
                ok = false;
                break;
            }
        }
        if (ok) cnt++;
    }

    cout << cnt;
    return 0;
    //ababababcx#ababababcx
    //001234560001234560000

}