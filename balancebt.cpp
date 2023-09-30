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

// balance bt - height(l)-height(r)<=1;
int height (node * root){
    if(root==NULL )return 0;

    int l=height(root->left);
    int r=height(root->right);
    return 1+max(l,r);
}
bool check(node *root){
    // o(n2) worst
    if(root==NULL)return true;

    int lh = height(root->left);
    int rh= height(root->right);

    if(abs(rh-lh)>1)return false;

    bool left = check(root->left);
    bool right = check(root->right);

    return true;
}

int optimise(node * root){
    if(root==NULL)return 0;
    
    //o(n), o(n);
    
    int l=height(root->left);
    int r=height(root->right);
    if(l==-1&& r==-1)return -1;
    if(abs(l-r)>1)return -1;
    return 1+max(l,r);

}

int main(){
    struct node * root=new node(1);
    
    root->left=new node(2);
    root->right=new node(3);
    root->left->right = new node(4);
    //root->left->right->right = new node(8);

    cout<<check(root);

    int c= optimise(root);
    if(c==-1) cout<<"not balance";
    else{
        cout<<"balance";
    }
}