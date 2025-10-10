#include <iostream>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;
    node(int m_val){
        val = m_val;
        left = NULL;
        right = NULL;
    }
};

void insert(node* &root, int val){
    node *m_node = new node(val);
    if(root == NULL) root = m_node;
    else{
        if(val <= root->val)insert(root->left, val);
        else insert(root->right, val);
    }
    

}

bool check(string s, node *m_root){
    node *cur = m_root;
    for(int i = 0; i < s.size();i++){
        if(cur == NULL) return false;
        else if(s[i] == 'L'){
            cur = cur->left;
        } else{
            cur = cur->right;
        }
    }

    if(cur != NULL) return true;
    else return false;

}


int main(){
    int n, q;
    cin >> n >> q;
    node* root = NULL;
    for(int i = 0; i < n;i++) {
        int x;
        cin >> x;
        insert(root, x);
    }

    for(int i = 0; i < q;i++){
        string s;
        cin >> s;
        if(check(s,root)) cout << "YES\n";
        else cout << "NO\n";

    }


}