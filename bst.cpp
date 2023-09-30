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

node* search(struct node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key)
        return root;
 
    // Key is greater than root's key
    if (root->data < key)
        return search(root->right, key);
 
    // Key is smaller than root's key
    return search(root->left, key);
}
int findceil(node *root, int key){

    int ceil=-1;
    while(root){
        if(root->data==key){
            ceil = root->data;
            return ceil;
        }
        else if(key>root->data){
            root=root->right;
        }
        else{
            ceil = root->data;
            root=root->left;
        }
    }
    return ceil;
}

node* insert(node* root, int key){
    if(root==NULL) return root= new node(key);

    node * curr=root;

    while(true){
        if(curr->data <=key){
            if(curr->right != NULL ) curr = curr->right;
            else{
                curr->right = new node(key);
                break;
            }
        }
        else{
            if(curr->left != NULL){
                curr= curr->left;
            }
            else{
                curr->left=new node(key);
                break;
            }
        }
    }
    return root;
}
node* deleteNode(node* root, int k){
    if (root == NULL)
        return root;
 
    if (root->data > k) {
        root->left = deleteNode(root->left, k);
        return root;
    }
    else if (root->data < k) {
        root->right = deleteNode(root->right, k);
        return root;
    }
 
    // If one of the children is empty
    if (root->left == NULL) {
        node* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL) {
        node* temp = root->left;
        delete root;
        return temp;
    }
 
    // If both children exist
    else {
 
        node* succParent = root;
 
        // Find successor
        node* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
 
        // Delete successor.  Since successor
        // is always left child of its parent
        // we can safely make successor's right
        // right child as left of its parent.
        // If there is no succ, then assign
        // succ->right to succParent->right
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
 
        // Copy Successor Data to root
        root->data = succ->data;
 
        // Delete Successor and return root
        delete succ;
        return root;
    }
}
void inorder(node* root)
{
    if (!root) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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
    
    //if(search(root,18)==NULL)cout<<"not found";
    //else cout<<"found";

    //cout<<findceil(root,14);

    insert(root,3);
    inorder(root);
    cout<<endl;
    deleteNode(root,3);
    inorder(root);

}