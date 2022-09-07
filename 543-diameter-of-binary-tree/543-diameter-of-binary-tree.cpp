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
    int maxlen=0;
    int diameterOfBinaryTree(TreeNode* root) {
        maxlenfun(root);
        return maxlen;
    }
    int maxlenfun(TreeNode *root)
    { 
        if(root==NULL)
        {
            return 0;
        }
            int left=maxlenfun(root->left);
            int right=maxlenfun(root->right);
            maxlen=max(maxlen,left+right);
            return 1+max(left,right);
    }
};