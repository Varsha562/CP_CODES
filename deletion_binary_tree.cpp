#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left =NULL; 
    node* right=NULL;
};
node* createnode(int data)
{
  node* newnode=new node();
  newnode->data=data;
  newnode->left=newnode->right=NULL;
  return newnode;
}
void deletelast(node* root,node* last)
{
    if(root==NULL)
    return;
    if(root->left==NULL && root->right==NULL)
    if(!root->data)
    return;
    queue<node*>q;
    q.push(root);
    node* temp=NULL;
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp==last)
        {
            temp=NULL;
            delete(temp);
            return;
        }
        if(temp->right==last)
        {
            temp->right=NULL;
            delete(temp->right);
            return;
        }
        else
         q.push(temp->right);
        if(temp->left==last)
        {
            temp->left=NULL;
            delete(temp->left);
            return;
        }
        else
        q.push(temp->left);
    } 
}
node* delete_node(int x,node* root)
{
    if(root==NULL)
    return NULL;
    if(root->left==NULL && root->right==NULL)
    if(!root->data)
    return NULL;
    else
    return root;
    queue<node*>q;
    q.push(root);
    node* temp=NULL;
    node* key=NULL;
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        if(temp->data==x)
        key=temp;
        if(temp->left)
        q.push(temp->left);
        if(temp->right)
        q.push(temp->right);
    }
    if(key!=NULL)
    {
        key->data=temp->data;
        deletelast(root,temp);
    }
    return root;
}
void inorder(node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    else
    return ;
}
int main()
{
    node* root = createnode(10);
    root->left = createnode(11);
    root->left->left = createnode(7);
    root->left->right = createnode(12);
    root->right = createnode(9);
    root->right->left = createnode(15);
    root->right->right = createnode(8);
 
    cout << "Inorder traversal before deletion : ";
    inorder(root);
 
    int key = 10;
    root = delete_node(key,root);
 
    cout << endl;
    cout << "Inorder traversal after deletion : ";
    inorder(root);
 
    return 0;
}
