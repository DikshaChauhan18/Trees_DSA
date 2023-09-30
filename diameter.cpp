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

// diameter = longest path between 2 nodes;
//brute force - max(lh,rh) betwen any 2 nodes -> o(n2)

int height(node * root){
    if(root==NULL)return 0;

    int l = height(root->left);
    int r= height(root->right);

    return 1+max(l,r);
}
int diameter(node *root){
    if(root==NULL)return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    int maxi = INT_MIN;
    maxi = max(maxi, lh+rh);

    diameter(root->left);
    diameter(root->right);

    return maxi;
}

int optimizediameter(node * root,int maxi){
    //o(n), o(n)
    if(root==NULL)return 0;

    int l = optimizediameter(root->left,maxi);
    int r= optimizediameter(root->right,maxi);
    maxi = max(maxi,l+r);
    return 1+max(l,r);
}
int main(){
    struct node * root=new node(1);
    
    root->left=new node(2);
    root->right=new node(3);
    root->left->right = new node(4);
    root->left->right->right = new node(8);
    root->left->right->right->left = new node(7);

    cout<<diameter(root);
    cout<<optimizediameter(root,0);
}