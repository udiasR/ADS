#include <iostream>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;
    node(int m_val){
        val = m_val;
        left = nullptr;
        right = nullptr;
    }
};


void bt_insert(node*&root, int x){
    if(root == nullptr){
        node* m_node  = new node(x);
        root = m_node;
    } else{
        if(x <= root->val) bt_insert(root->left, x);
        else bt_insert(root->right, x);
    }
}

int cnt = 0;

void travel(node* &cur){
    if(cur == nullptr) return;
    else {
        if(cur->left != NULL && cur->right != NULL) cnt++;
        travel(cur->left);
        travel(cur->right);
    }
}


int main(){
    int n;
    cin >> n;
    node*root = nullptr;
    for(int i = 0; i < n;i++){
        int x;
        cin >> x;
        bt_insert(root, x);
    }
    travel(root);
    cout << cnt;
}