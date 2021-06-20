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
public:
         int max_sum=0;
     struct info{
    int max_val;
    int min_val;
    bool isbst;
    int sum;
    };
    info solve(TreeNode* root)
    {
       if(!root)
       {
           return {INT_MIN,INT_MAX,true,0};
       }
        info l=solve(root->left);
        info r=solve(root->right);
        info x;
        if(l.isbst && r.isbst && l.max_val<root->val && r.min_val>root->val)
        {
            x.isbst=true;
            x.max_val=max(root->val,r.max_val);
            x.min_val=min(root->val,l.min_val);
            x.sum=l.sum+r.sum+root->val;
        }
        else
        {
            x.isbst=false;
            x.max_val=max(root->val,r.max_val);
            x.min_val=min(root->val,l.min_val);
            x.sum=max(l.sum,r.sum);
        }
        max_sum=max(max_sum,x.sum);
        //cout<<max_sum<<endl;
        return x;
    }
    int maxSumBST(TreeNode* root) {
       solve(root);
        return max_sum;
    }
};
