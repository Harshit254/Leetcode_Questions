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
    int maxdiff(TreeNode* root,int mn,int mx)
    {
        if(root==NULL)
        {
            return mx-mn;
        }
        mx=max(mx,root->val);
        mn=min(mn,root->val);
        
        return max(maxdiff(root->left,mn,mx),maxdiff(root->right,mn,mx));
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root==NULL) return 0;
      return maxdiff(root,1e6,0);  
    }
};