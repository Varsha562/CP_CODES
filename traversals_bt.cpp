#include<bits/stdc++.h>
using namespace std;
struct node{
    int key;
    node* left=NULL;
    node* right=NULL;
};
node* newNode(int data)
{
    if(!data)
    return NULL;
    node* newnode=new node();
    newnode->key=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
void inorder(node* temp)
{
    if(temp==NULL)
    return;
    inorder(temp->left);
    cout<<temp->key<<" ";
    inorder(temp->right);
}
void postorder(node* temp)
{
    if(temp==NULL)
    return;
    postorder(temp->left);
    postorder(temp->right);
    cout<<temp->key<<" ";
}
void preorder(node* temp)
{
    if(temp==NULL)
    return;
    cout<<temp->key<<" ";
    preorder(temp->left);
    preorder(temp->right);
}
int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    cout << "\nPreorder traversal of binary tree is \n";
    preorder(root);
 
    cout << "\nInorder traversal of binary tree is \n";
    inorder(root);
 
    cout << "\nPostorder traversal of binary tree is \n";
    postorder(root);
 
    return 0;
}
