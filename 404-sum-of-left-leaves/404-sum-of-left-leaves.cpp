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
    int sum=0;
    void function(TreeNode* root,bool istrue)
    {
        if(root==NULL) return;
        
        if(istrue && root->left==NULL && root->right==NULL)
        {
            sum+=root->val;
        }
        function(root->left,true);
        function(root->right,false);
    }
int sumOfLeftLeaves(TreeNode* root) {
        function(root,false);
        return sum;
    }
};