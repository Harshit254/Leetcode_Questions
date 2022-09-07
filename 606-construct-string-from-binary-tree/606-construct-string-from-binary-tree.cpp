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
    string s;
    string tree2str(TreeNode* root) {
        if(!root) return "";
        s=to_string(root->val);
        if(root->left!=NULL)
        {
            s=s+'('+tree2str(root->left)+')';
            
        }
        else if(root->right)
        {
            s+="()";
        }
        
        if(root->right!=NULL)
        {
            s=s+'('+tree2str(root->right)+")";
        }
        return s;
    }
};