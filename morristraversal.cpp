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

// threaded bt concept

void inorder(node * root){
    node * curr=root;
    while(curr!=NULL){
        if(curr->left==NULL){
            cout<<curr->data;
            curr=curr->right;
        }
        else{
            node * prev =curr->left;
            while(prev->right && prev->right !=curr){
                prev = prev->right;
            }
            if(prev->right ==NULL){
                prev->right = curr;
                curr=curr->left;
            }
            else{
                prev->right =NULL;
                cout<<curr->data;
                curr=curr->right;
            }
        }
    }
}


void preorder(node * root){
    node * curr=root;
    while(curr!=NULL){
        if(curr->left==NULL){
            cout<<curr->data;
            curr=curr->right;
        }
        else{
            node * prev =curr->left;
            while(prev->right && prev->right !=curr){
                prev = prev->right;
            }
            if(prev->right ==NULL){
                prev->right = curr;
                cout<<curr->data;
                curr=curr->left;
            }
            else{
                prev->right =NULL;
                
                curr=curr->right;
            }
        }
    }
}


int main(){
    struct node * root=new node(1);
    
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->left->right->left=new node(6);
    root->left->right->right=new node(7);

    inorder(root);
    preorder(root);
    //o(n), o(1);
}