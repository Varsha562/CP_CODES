#include<bits/stdc++.h>
using namespace std;
struct node{
    int key;
    node* left;
    node* right;
};
node* createnode(int data)
{
    node* newnode=new node();
    newnode->key=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
node* insert(node* root,int temp)
{
    if(root==NULL)
    {
       root=createnode(temp);
       return root;
    }
    if(root->key<temp)
    {
       root->right=insert(root->right,temp);
    }
    else
    root->left=insert(root->left,temp);
}
void inordertraversal(node* root)
{
    if(root==NULL)
    {
        return;
    }
    inordertraversal(root->left);
    cout<<root->key<<" ";
    inordertraversal(root->right);
}
int main()
{
    node* root = NULL;
    root=insert(root,50);
    insert(root,30);
    insert(root,20);
    insert(root,40);
    insert(root,70);
    insert(root,60);
    insert(root,80); 
 
    cout << "Inorder traversal after insertion: ";
    inordertraversal(root);
    cout << endl;
 
    return 0;
}
