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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        inordertraversal(root,res);
        return res;
    }
    void inordertraversal(TreeNode *root,vector<int>&res)
    {
        if(root==NULL)
            return;
        else
        {
            inordertraversal(root->left,res);
            res.push_back(root->val);
            inordertraversal(root->right,res);
        }
    }
    
};