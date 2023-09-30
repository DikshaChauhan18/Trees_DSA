// tree - heriarchy data structure

/*
1-full bt - either 2 or 0 children
2-cbt- all lvl should be completely filled and last should as left as possible
3-perfect bt - all leaf nodes are at same lvl
4-balance bt- height of tree at max = log n
   n- no of nodes  let n=8, height log 8=3
5- degenarate tree -every node has single children 
*/

// binary tree structure

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
void inorder(node * root){
    //lnr
    /*
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    */
   //iterative
    if(root==NULL)return;
    stack<node *>s;
    node * node = root;
    while(true){
      if(node!=NULL){
          s.push(node); //store root in stack and traverse as left as possible
          node=node->left;
      }
      else{
            if(s.empty()==true)break;
            node = s.top();
            s.pop();
            cout<<node->data<<" ";
            node=node->right;
      }
       
    }
}
void preorder(node * root){
    //nlr
    /*
    if(root==NULL)return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    */
   //iterative o(n)tc worst-sc o(n)
   if(root==NULL)return;
   stack<node *>s;
   s.push(root);
   while(!s.empty()){
       node* top=s.top();
       s.pop();
       cout<<top->data<<" ";
       if(top->right!=NULL)s.push(top->right); //phle right cz stack is lifo so left phle aane k lie right phle likha
       if(top->left!= NULL)s.push(top->left);
       
   }
}
void postorder(node * root){
    //lrn
/*   
    if(root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
*/  
/*
    //iterative ======2stack
    if(root==NULL)return;
    stack<node*>s1;
    stack<node*>s2;
    s1.push(root);
    node *temp;
    while(!s1.empty()){
        temp=s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left!=NULL)s1.push(temp->left);
        if(temp->right!=NULL)s1.push(temp->right);
    }
    while(!s2.empty()){
        temp = s2.top();
        s2.pop();
        cout<<temp->data<<" ";
    }
    */
    
    
}
void levelorder(node *root){
    //bfs o(n)-BOTH TC AND SC
    if(root==NULL)return;
    queue<node*>q;
    q.push(root);
    while(q.empty()==false){
            node* front = q.front();
            cout<<front->data<<" ";
            q.pop();
            if(front->left!=NULL)q.push(front->left);
            if(front->right!=NULL)q.push(front->right);                         
    }
}

int main(){
    struct node * root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->right = new node(4);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;
    levelorder(root);
}