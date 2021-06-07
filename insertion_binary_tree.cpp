#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
struct node
{
    int data;
    node* left;
    node* right;
};
node* createnode(int data)
{
    node* newnode=new node();
    newnode->data=data;
    newnode->right=NULL;
    newnode->left=NULL;
    return newnode;
}
node* insertnode(node* root, int data)
{
    if(root==NULL)
    {
        root=createnode(data);
        return root;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node* x=q.front();
        q.pop();
        if(x->left!=NULL)
        q.push(x->left);
        else
        {
            x->left=createnode(data);
            return root;
        }
        if(x->right!=NULL)
        q.push(x->right);
        else
        {
            x->right=createnode(data);
            return root;
        }
    }
}
void inordertraversal(node* root)
{
    if(root==NULL)
    {
        return;
    }
    inordertraversal(root->left);
    cout<<root->data<<" ";
    inordertraversal(root->right);
}
int main()
{
    node* root = createnode(10);
    root->left = createnode(11);
    root->left->left = createnode(7);
    root->right = createnode(9);
    root->right->left = createnode(15);
    root->right->right = createnode(8);
 
    cout << "Inorder traversal before insertion: ";
    inordertraversal(root);
    cout << endl;
 
    int key = 12;
    root = insertnode(root, key);
 
    cout << "Inorder traversal after insertion: ";
    inordertraversal(root);
    cout << endl;
 
    return 0;
}
