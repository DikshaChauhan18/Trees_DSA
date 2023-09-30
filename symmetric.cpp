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
bool issymmetric(node *left,node* right){
    if(left==NULL || right == NULL)return left==right;

    if(left->data!=right->data)return false;

    return issymmetric(left->left,right->right) && issymmetric(left->right,right->left);

}
bool check (node *root){
    if(root==NULL)return true;
    return issymmetric(root->left,root->right);
}

int main(){
    struct node * root=new node(1);
    
    //root->left=new node(3);
    root->right=new node(3);
    //root->right->left=new node(9);
  
    cout<<check(root);
}