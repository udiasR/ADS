#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
    int val;
    node* right;
    node* left;

    node(int m_val){
        val = m_val;
        left = nullptr;
        right= nullptr; 
    }
};


void insert(node*&root, int x){

    if(root == nullptr){
        node* m_node  = new node(x);
        root = m_node;
    } else{
        if(x <= root->val) insert(root->left, x);
        else insert(root->right, x);
    }
}
vector<int>output;

void print(node*root){
    if(root == nullptr)return;
    output.push_back(root->val);
    print(root->left);
    print(root->right);
}

int main(){
    int n;
    cin >> n;
    vector<int>v(n);
    
    node*root = nullptr;
    for(int i = 0; i < n;i++)cin >> v[i];
    sort(v.begin(), v.end());
    vector<int>pref(n+1);
    pref[0] = 0;
    for(int i = 1; i <= n;i++)pref[i] = pref[i-1] + v[i-1];

    for(int i = 1; i <= n;i++){
        insert(root, pref[n] - pref[i-1]);
    }
    print(root);
    for(int i = output.size()-1; i >= 0;i--)cout << output[i] << " ";

}