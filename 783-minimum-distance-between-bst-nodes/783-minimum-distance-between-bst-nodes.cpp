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
    vector<int>ans;
    void bst(TreeNode* root,vector<int>&ans)
    {
        if(!root) return;
        bst(root->left,ans);
        ans.push_back(root->val);
        bst(root->right,ans);
    }
    int minDiffInBST(TreeNode* root) {
        bst(root,ans);
        int mn=INT_MAX;
        for(int i=0;i<ans.size()-1;i++)
        {
            mn=min(mn,(ans[i+1]-ans[i]));
        }
        return mn;
    }
};