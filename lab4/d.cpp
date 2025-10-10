#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;
    node(int m_val){
        left = nullptr;
        right = nullptr;
        val = m_val;
    }
};

void bt_insert(node*&root, int x){
    if(root == nullptr){
        node* m_node = new node(x);
        root= m_node;
    } else if(x <= root->val) bt_insert(root->left, x);
    else bt_insert(root->right, x);
}

int arr[5000];

int maxlvl = 0;
void sum_oflevels(node*&root, int lvl){
    if(root == nullptr)return;
    arr[lvl] +=root->val;
    sum_oflevels(root->left, lvl+1);
    sum_oflevels(root->right, lvl+1);
    maxlvl = max(maxlvl, lvl);
}

int main(){
    node*root = nullptr;
    int n,x;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> x, bt_insert(root, x);
    
    sum_oflevels(root, 0);
    
    cout << maxlvl + 1 << '\n';
    
    for(int i = 0; i <= maxlvl; i++) cout << arr[i] << ' '; 
    
    return 0;
}