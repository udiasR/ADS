#include <iostream>
#include <vector>
#include <algorithm>
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


void insert(node*&root, int val){
    if(root == nullptr) {
            node* m_node = new node(val);
            root = m_node;
    } else{
            if(val <= root->val)insert(root->left, val);
            else insert(root->right, val);
        }

}
void print(node* root) {
    if(root == nullptr) return;
    cout << root->val << " ";
    print(root->left);
    print(root->right);
}


void search(node*&root, int val){
    node* cur = root;
    while(cur != nullptr){
        if(cur->val == val){
            print(cur);
            cout << "\n";
            return;
        } else{
            if(val <= cur->val) cur = cur->left;
            else cur = cur->right;
        }
    }

}



int main(){
    int n;
    cin >> n;
    node* root = nullptr;
    for(int i = 0; i < n;i++){
        int x;
        cin >> x;
        
        insert(root, x);
    }
    int t;
    cin >> t;
     search(root, t);


    
    

}