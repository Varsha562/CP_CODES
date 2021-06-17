#include<bits/stdc++.h>
using namespace std;
int arr[100];
struct node{
    int key;
    node* left;
    node* right;
};
node* createnode(int data)
{
    node* temp=new node();
    temp->key=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return createnode(key);
 
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
 
    /* return the (unchanged) node pointer */
    return node;
}
node* deletenode(node* root,int k)
{
    if(root==NULL)
    return root;
    if(k<root->key)
    {
        root->left=deletenode(root->left,k);
        return root;
    }
    else
    if(k>root->key)
    {
        root->right=deletenode(root->right,k);
        return root;
    }
    else
    {
    if(root->right==NULL)
    {
        node* temp=root->left;
        delete root;
        return temp;
    }
    else
    if(root->left==NULL)
    {
        node* temp=root->right;
        delete root;
        return temp;
    }
    else
    {
    node* par=root;
    node* x=root->right;
    while(x->left!=NULL)
    {
    par=x;
    x=x->left;
    }
    if(par!=root)
    par->left=x->right;
    else
    par->right=x->right;
    root->key=x->key;
    delete x;
    return root;
    }
    }
}
void inorder(node* temp)
{
    if(temp==NULL)
    return;
    inorder(temp->left);
    cout<<temp->key<<" ";
    inorder(temp->right);
}
int main()
{
    /* Let us create following BST
            50
        /     \
        30     70
        / \ / \
    20 40 60 80 */
    struct node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
 
    cout << "Inorder traversal of the given tree \n";
    inorder(root);
 
    cout << "\nDelete 20\n";
    node* x=deletenode(root, 20);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);
 
    cout << "\nDelete 30\n";
    root=deletenode(root, 30);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);
 
    cout << "\nDelete 50\n";
    root=deletenode(root, 50);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);
 
    return 0;
}
