#include <iostream>
#include <vector>
using namespace std;

vector<int> lps(string pat){
    int m = pat.size(); 
    int i = 1, len = 0;
    vector<int>lps(m,0);
    while(i < m){
        if(pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        } else{
            if(len == 0)i++;
            else len = lps[len-1];
        }
    }
    return lps;
}

int KMPsearch(string pat, string txt){
    int n = txt.size();
    int m = pat.size();

    int i = 0, j = 0;
    vector<int>olps = lps(pat); 

    while(i < n){
        if(pat[j] == txt[i]){
            i++;
            j++;
            if(j == m){
                return i-j;
                j = olps[j-1];
            }
        } else{
            if(j != 0) j = olps[j-1];
            else i++;
        }
    }
    return -1;
}


int main(){
    string s,t;
    cin >> s >> t;
    string nstr = s+s; 
    int res = KMPsearch(t,nstr);
    if(res == -1)cout << -1;
    else cout << s.size() - res;
}