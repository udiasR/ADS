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


bool kmpSearch(string txt, string pat){
    int n = txt.size();
    int m = pat.size();
    int i = 0, j = 0;
    vector<int>olps = lps(pat);
    while(i < n){
        if(pat[j] == txt[i]){
            i++;
            j++;
            if(j == m){
                return true;
            }
        } else{
            if(!j)i++;
            else j = olps[j-1];
        }
    }
    return false;
}

int minRep(string a, string b){
    string rep = a;
    int cnt = 1;
    while(rep.size() < b.size()){
        rep+=a;
        cnt++;
    }

    if(kmpSearch(rep,b))return cnt;
    if(kmpSearch(rep+a, b))return cnt+1;

    return -1;

}

int main(){
    string a,b;
    cin >> a >> b;    
    cout << minRep(a,b);
}