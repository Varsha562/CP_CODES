#include<bits/stdc++.h>
using namespace std;
struct node{
    int key;
    node*left=NULL;
    node*right=NULL;
};
node* createnode(int data)
{
    node* newnode=new node();
    newnode->key=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
void inorder(node* root)
{
    if(!root)
    {
        cout<<"\0";
        return;
    }
    stack<node*>s;
    s.push(root);
    node* curr=root;
    while(!s.empty())
    {
       // cout<<s.top()->key<<endl;
        while(curr->left!=NULL)
        {
            s.push(curr->left);
            curr=curr->left;
        }
         node* temp=s.top();
          s.pop();
            if(temp->right!=NULL)
            {
                s.push(temp->right);
                curr=temp->right;
            }
            cout<<temp->key<<" ";
    }
}
int main()
{
 
    /* Constructed binary tree is
              1
            /   \
          2      3
        /  \
      4     5
    */
    node *root = createnode(1);
    root->left        = createnode(2);
    root->right       = createnode(3);
    root->left->left  = createnode(4);
    root->left->right = createnode(5);
 
    inorder(root);
    return 0;
}
