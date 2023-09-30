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


//perform any traversal it should be same for both o(n), o(n)

bool check(node *r1, node* r2){
    if(r1==NULL || r2 ==NULL)return true;
    if(r1==NULL && r2 !=NULL)return false;
    if(r1!=NULL && r2 ==NULL)return false;

    bool l = check(r1->left , r2->left);
    bool r= check(r1->right,r2->right);

    return ((r1->data==r2->data)&&l&&r);

}

int main(){
    struct node * root=new node(1);
    
    root->left=new node(3);
    root->right=new node(7);
    root->right->left=new node(9);

    struct node * root2=new node(1);
    
    root2->left=new node(3);
    root2->right=new node(7);
    root2->right->left=new node(9);
    
    cout<<check(root,root2);
}