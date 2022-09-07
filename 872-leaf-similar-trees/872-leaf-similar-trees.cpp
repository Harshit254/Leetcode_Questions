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
public:vector<int>v1,v2;
    void function(TreeNode* root)
    {
        if(!root) return;
        
        if(root && root->left==NULL && root->right==NULL) v1.push_back(root->val);
        function(root->left);
        function(root->right);
    }
    void function2(TreeNode* root)
    {
        if(!root) return;
        
        if(root && root->left==NULL && root->right==NULL) v2.push_back(root->val);
        function2(root->left);
        function2(root->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return true;
        if((!root1 && root2) || (root1 && !root2)) return false;
        function(root1);
        function2(root2);
        return v1==v2;
    }
};