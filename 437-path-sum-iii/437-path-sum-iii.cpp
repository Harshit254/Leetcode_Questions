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
    int function(TreeNode* root,long  res)
    {
        if(root==NULL) return 0;
        long ans=0;
        if(res==root->val)ans++;
        ans+=function(root->left,res-root->val);
        ans+=function(root->right,res-root->val);
        
        return ans;
    }
    int pathSum(TreeNode* root, int res) {
        if(root==NULL) return 0;
        
        return pathSum(root->left,res)+function(root,res)+pathSum(root->right,res);
    }
};