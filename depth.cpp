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

int reccdepth(node * root){

    // tc - o(n)  sc o(n)worst 
    if(root==NULL)return 0;
    if(root->left==NULL && root->right==NULL)return 1;
    int l=reccdepth(root->left);
    int r= reccdepth(root->right);
    return 1+max(l,r);
}

int main(){
    struct node * root=new node(1);
    
    root->left=new node(2);
    root->right=new node(3);
    root->left->right = new node(4);

    cout<<reccdepth(root);
}