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
    int count=0;
    void function(TreeNode* root,int v)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->val>=v)
        {
            count++;
        }
        v=max(root->val,v);
        function(root->left,v);
        function(root->right,v);
    }
    int goodNodes(TreeNode* root) {
        int v=root->val;
        
        function(root,v);
        return count;
    }
};