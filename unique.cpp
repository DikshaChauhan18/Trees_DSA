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
/*
using preorder and postorder we cannot create any unique tree


*/
node * constructTree(vector<int>&preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd,
map<int,int>&mp) {
    
    if (preStart > preEnd || inStart > inEnd) return NULL;

    node * root = new node(preorder[preStart]);
    int elem = mp[root -> data];
    int nElem = elem - inStart;

    root -> left = constructTree(preorder, preStart + 1, preStart + nElem, inorder,inStart, elem - 1, mp);
    root -> right = constructTree(preorder, preStart + nElem + 1, preEnd, inorder, elem + 1, inEnd, mp);

    return root;
}

node * buildTree(vector < int > & preorder, vector < int > & inorder) {
    int preStart = 0, preEnd = preorder.size() - 1;
    int inStart = 0, inEnd = inorder.size() - 1;

    map < int, int > mp;
    for (int i = inStart; i <= inEnd; i++) {
        mp[inorder[i]] = i;
    }

    return constructTree(preorder, preStart, preEnd, inorder, inStart, inEnd, mp);
}
void inorderprint(node * root){
    //lnr
   
    if(root==NULL)return;
    
    inorderprint(root->left);
    cout<<root->data<<" ";
    inorderprint(root->right);
}
int main(){
    /*
    struct node * root=new node(1);
    
    root->left=new node(2);
    root->right=new node(3);
    
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->left->right->left=new node(6);
    root->left->right->right=new node(7);
*/
    vector<int> preorder{10,20,40,50,30,60};
    vector<int> inorder{40,20,50,10,60,30};
    node * root = buildTree(preorder, inorder);

    inorderprint(root);
}