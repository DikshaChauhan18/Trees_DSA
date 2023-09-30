#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node * left;
    node * right;

    node(int val){
        data=val;
        left=right=NULL;
    }
    
};
// bt to ll
//right left root
//o(n) o(N)
class sol{
    node * prev =NULL;
    public:

void flatten(node * root){
    if (root == NULL) return;

      flatten(root -> right);
      flatten(root -> left);

      root -> right = prev;
      root -> left = NULL;
      prev = root;

}
};

int main(){
    struct node * root=new node(1);
    
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->left->right->left=new node(6);
    root->left->right->right=new node(7);

    sol obj;
    
    obj.flatten(root);
    while(root->right!=NULL){
      cout<<root->data<<"->";
      root=root->right;
    }
    cout<<root->data;






}