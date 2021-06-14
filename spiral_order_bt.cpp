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
void spiral(node* root)
{
    stack<node*>s1,s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty())
    {
        while(!s1.empty())
        {
            node* temp=s1.top();
            cout<<temp->key<<" ";
            s1.pop();
            if(temp->right!=NULL)
            s2.push(temp->right);
            if(temp->left!=NULL)
            s2.push(temp->left);
        }
        while(!s2.empty())
        {
             node* temp=s2.top();
            cout<<temp->key<<" ";
            s2.pop();
            if(temp->left!=NULL)
            s1.push(temp->left);
            if(temp->right!=NULL)
            s1.push(temp->right);
        }
    }
}
int main()
{
    node* root = createnode(1);
    root->left = createnode(2);
    root->right = createnode(3);
    root->left->left = createnode(7);
    root->left->right = createnode(6);
    root->right->left = createnode(5);
    root->right->right = createnode(4);
    cout << "Spiral Order traversal of binary tree is \n";
    spiral(root);
  
    return 0;
}
