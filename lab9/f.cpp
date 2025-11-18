#include <iostream>
#include <vector>
using namespace std;


vector<int> lps(string s2){
    int n = s2.size();
    vector<int>lps(n,0);
    int len = 0;
    int i = 1;
    while (i < n){
        if(s2[i] == s2[len]){
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
    string s1,s2;
    cin >> s1 >> s2;
    vector<int>lps2 = lps(s2);

    int i = 0, j = 0;
    vector<int>res;
    int n = s1.size(), m = s2.size();
    while(i < n){
        if(s1[i] == s2[j]){
            i++;
            j++;

            if(j == m){
                res.push_back(i-j+1);
                j = lps2[j - 1];
            }
        } else{
            if(!j){
                i++;
            }else{
                j = lps2[j-1];
            }
        }
    }
    cout << res.size() << "\n";
    for(int i = 0; i < res.size();i++){
        cout << res[i] << " ";
    }
}