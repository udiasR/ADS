#include <iostream>
#include <vector>

using namespace std;

vector<int> lps(string s){
    int n = s.size();
    int i = 1, len = 0;
    vector<int>lps(n,0);

    while(i < n){
        if(s[i] == s[len]){
            len++;
            lps[i] = len;
            i++;
        } else{
            if(!len){
                lps[i] = 0;
                i++;}
            else{
                len = lps[len-1];
            }
        }
    }
    return lps;
}


int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int>olps = lps(s);

    cout << n - olps[n-1];
}