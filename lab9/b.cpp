#include <iostream>
#include <vector>
using namespace std;


vector<int> lps(string s, int m ){
    int n = s.size();
    int len = 0, i = m;
    vector<int>lps(n,0);
    while(i < n){
        if(s[i] == s[len]){
            len++;
            lps[i] = len;
            i++;
        } else{
            if(!len){
                lps[i] = 0;
                i++;
            } else{
                len = lps[len-1];
            }
        }
    }
    return lps;
}

int main(){
    string pat, s;
    int n;

    cin >> pat >> n >> s;

    string newstr = pat+ '#' + s;
    int m = pat.size()+1;
    vector<int>olps = lps(newstr, m);

    int cnt = 0;

    for(int i = m;i < newstr.size();i++){
        if(olps[i] == pat.size())cnt++;
    }
    if(n <= cnt)cout << "YES";
    else cout << "NO";
}