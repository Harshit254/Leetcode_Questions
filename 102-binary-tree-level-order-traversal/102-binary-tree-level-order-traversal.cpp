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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        leftorderaf(root,0,res);
        return res;
    }
    void leftorderaf(TreeNode *root, int level,vector<vector<int>>&res)
    {
        if(root==NULL)
        {
            return;
        }
        else
        {
            if(level>=res.size())
            {
                res.push_back({root->val});
            }
            else
            {
               res[level].push_back(root->val); 
            }
            leftorderaf(root->left,level+1,res);
            leftorderaf(root->right,level+1,res);
        }
        
            
    }
};