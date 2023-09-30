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
//parent pointer
//move 1 distance up down
// if dis == k stop and print the ans;

void solve(node *root,node* target,int k,vector<int>&ans){
   
        unordered_map<int, node*> parent;
        queue<node*> q;
        q.push(root);

        while(!q.empty()){
            int si = q.size();
            for(int i = 0; i < si; i++){
                auto top = q.front();
                q.pop();
                
                if(top -> left){
                    parent[top->left->data] = top;
                    q.push(top->left); 
                }

                if(top -> right){
                    parent[top->right->data] = top;
                    q.push(top->right); 
                }
            }
        }

        unordered_map<int, int> visited;
        q.push(target);
        while(k-- && !q.empty()){
            int size = q.size();

            for(int i = 0; i < size; i++){
                auto top = q.front();
                q.pop();

                visited[top -> data] = 1;

                if(top -> left && !visited[top->left->data]){
                    q.push(top -> left);
                }

                if(top -> right && !visited[top->right->data]){
                    q.push(top -> right);
                }

                if(parent[top->data] && !visited[parent[top->data] -> data]){
                    q.push(parent[top->data]);
                }

            }
        }

        while(!q.empty()){
            ans.push_back(q.front()->data);
            q.pop();
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
    node* target = root->left;
    vector<int>ans;
    solve(root,target,2,ans);

    for(auto i: ans){
        cout<<i<<endl;
    }
}