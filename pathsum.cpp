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


int maxpath(node *root,int &maxi){
    if(root == NULL)return 0;

    int lsum = max(0,maxpath(root->left,maxi));
    int rsum = max(0,maxpath(root->right,maxi));
    maxi = max(maxi,(lsum+rsum)+root->data);
    return root->data+ max(lsum,rsum);
}

int main(){
    struct node * root=new node(1);
    
    root->left=new node(3);
    root->right=new node(7);
    root->right->left=new node(9);
    
    int maxi=0;
    maxpath(root,maxi);
    cout<<maxi;
}