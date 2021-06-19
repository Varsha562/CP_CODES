/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<int>arr;
public:
    TreeNode* createnode(int x)
    {
        TreeNode* temp=new TreeNode();
        temp->val=x;
        temp->left=NULL;
        temp->right=NULL;
        return temp;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        TreeNode* rootnew=NULL;
        if(arr.size()==1 || arr.size()==2)
            return root;
          rootnew= balance(arr,0,arr.size()-1);
        return rootnew;
    }
    TreeNode* balance(vector<int>arr,int start,int end)
    {
        if(start>end)
        return NULL;
        int mid=(start+end)/2;
        TreeNode* root=createnode(arr[mid]);
        root->left=balance(arr,start,mid-1);
        root->right=balance(arr,mid+1,end);
        return root;
    }
    void inorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }
};
