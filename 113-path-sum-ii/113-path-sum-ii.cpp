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
    void function(TreeNode* root,int target,vector<vector<int>>&ans,vector<int>&dp)
    {
        if(root==NULL)
        {
            return;
        }
        dp.push_back(root->val);
        target=target-root->val;
        if(root->left==NULL && root->right==NULL && target==0)
        {
            ans.push_back(dp);
        }
            //dp.push_back(root->val);
            function(root->left,target,ans,dp);
            //dp.pop_back();
            function(root->right,target,ans,dp);
            dp.pop_back();
            target=target+root->val;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>dp;
        function(root,targetSum,ans,dp);
        return ans;
    }
};