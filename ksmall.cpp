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
void inorder(node * root, vector<int>&ans){
    if(root==NULL)return;

    
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
int ksmall(node* root, int k){
    vector<int>ans;
    inorder(root,ans);
    return ans[k-1];
}
node* kthsmallest(node* root,int &k)
{
	if(root==NULL)
	return NULL;
	
	node* left=kthsmallest(root->left,k);
	if(left!=NULL)return left;
	k--;
	if(k==0)return root;
	
	return kthsmallest(root->right,k);
}
int main(){
    struct node * root=new node(8);
    
    root->left=new node(5);
    root->right=new node(12);
    
    root->left->left=new node(4);
    root->left->right=new node(7);
    root->left->right->left=new node(6);

    root->right->left=new node(10);
    root->right->right=new node(15);
    root->right->right->left=new node(13);

    cout<<ksmall(root,3);
    int k=3;
    cout<<(kthsmallest(root,k))->data;
}