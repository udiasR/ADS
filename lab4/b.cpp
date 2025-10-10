#include <iostream>
using namespace std;

struct node{
    int val;
    node* right;
    node* left;
    node(int m_val){
        val = m_val;
        right = NULL;
        left = NULL;
    }
};



void bst_insert(node*& root, int m_val){
    node* m_node = new node(m_val);
    if(root == NULL) root = m_node;
    else{
        if(root->val <= m_val) bst_insert(root->left, m_val );
        else bst_insert(root->right, m_val);
    }
}

int count(node* cur){
    if(cur == NULL) return 0;
    else return 1 + count(cur->left) + count(cur->right);
}

int search(node*& cur, int head){
    if(cur == NULL) return 0;
    else if(cur->val == head) return count(cur);
    else if(cur->val <= head) return search(cur->left, head);
    else return search(cur->right, head);


}




int main(){
    int n;
    cin >> n;
    node* root = NULL;
    for(int i = 0; i < n;i++){
        int x;
        cin >> x;
        bst_insert(root, x);
    }

    int head;
    cin >> head;

    node*cur = root;
    cout << search(cur, head);




}