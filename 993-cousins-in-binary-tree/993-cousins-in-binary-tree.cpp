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
    int l1=0,l2=0;
    int r1=0,r2=0;
    void getlevel(TreeNode* root,int n,int level)
    {
        if(!root) return;
        if( root->left && root->left->val==n)
        {
            l1=level+1;
            r1=root->val;
            return;
        }
        if(root->right && root->right->val==n)
        {
            l1=level+1;
            r1=root->val;
            return;
        }
        getlevel(root->left,n,level+1);
        getlevel(root->right,n,level+1);
    }
    void getlevel2(TreeNode* root,int n,int level)
    {
        if(!root) return;
        if(root->left && root->left->val==n)
        {
            l2=level+1;
            r2=root->val;
            return;
        }
        if(root->right && root->right->val==n)
        {
            l2=level+1;
            r2=root->val;
            return;
        }
        getlevel2(root->left,n,level+1);
        getlevel2(root->right,n,level+1);
    }
        bool isCousins(TreeNode* root, int x, int y) {
       if(!root) return false;
       getlevel(root,x,0);
       getlevel2(root,y,0);
        if(l1==l2 && r1!=r2) return true;
        return false;
    }
};