#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> lps(string s){
    int n = s.size();
    int i = 1,len = 0;
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
    string s;
    cin >> s;
    int n;
    s[0] =tolower(s[0]);
    cin >> n;
    vector<string>cities(n);
    for(int i = 0; i < n;i++){cin >> cities[i];
    cities[i][0] = tolower(cities[i][0]);}

    vector<int>possible(n);
    int best = 0;
    for(int i = 0; i < n;i++){
        string nstr = cities[i] + '#' + s;
        vector<int>bin = lps(nstr);
        possible[i] = bin.back();
        best = max(best, possible[i]);
    }

    cout << count(possible.begin(), possible.end(), best) << "\n";
    for (int i = 0; i < n; i++)
        if (possible[i] == best) {
            cities[i][0] = toupper(cities[i][0]);
            cout << cities[i] << "\n";}

}