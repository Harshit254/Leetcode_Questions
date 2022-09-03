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
    int lt=0;
    void function(TreeNode* root,int lt)
    {
        if(root==NULL) return;
        if(root->left == NULL && root->right==NULL){
            lt = lt*10 + root->val;
            sum += lt;
            return;
        }
        lt=lt*10+root->val;
        function(root->left,lt);
        function(root->right,lt);
    }
    int sumNumbers(TreeNode* root) {
        function(root,0);
        return sum;
    }
};