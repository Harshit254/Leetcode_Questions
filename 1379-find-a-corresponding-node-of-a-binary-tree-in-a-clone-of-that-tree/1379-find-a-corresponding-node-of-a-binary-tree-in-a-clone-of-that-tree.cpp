/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void function(TreeNode* root,TreeNode* target,TreeNode* &res)
    {
        if(root==NULL)
        {
            return;
        }
        
        if(root->val==target->val)
        {
            res=root;
            return;
        }
        function(root->left,target,res);
        function(root->right,target,res);
        
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* res=new TreeNode(-1);
        
        function(cloned,target,res);
        return res;
    }
};