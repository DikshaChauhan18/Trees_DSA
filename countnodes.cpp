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

// traverse using any traversal and c++; o(n), o(n)

// optimze = lh+rh+1;   o(logn sq),  o(log n)
int lh (node* root){
    int ans =0;
    while(root){
        ans++;
        root=root->left;
    }
    return ans;
}
int rh (node* root){
    int ans =0;
    while(root){
        ans++;
        root=root->right;
    }
    return ans;
}
int count(node * root)
{
    if(root==NULL)return 0;
    int l = lh(root);
    int r= rh(root);

    if(l==r) return (1<<l)-1;

    return 1+count(root->left)+count(root->right);
}


int main(){
    struct node * root=new node(1);
    
    root->left=new node(2);
    root->right=new node(3);
    
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->left->right->left=new node(6);
    root->left->right->right=new node(7);

    cout<<count(root);
}