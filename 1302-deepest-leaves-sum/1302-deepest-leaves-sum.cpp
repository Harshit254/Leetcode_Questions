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
    int height(TreeNode* root){
        if(root==NULL)return 0;
        int left=height(root->left);
        int right=height(root->right);
        return 1+max(left,right);
        
    }
    void function(TreeNode* root,int height,int x){
        if(root==NULL)return;
        if(x==height){
            sum+=root->val;
        }
        function(root->left,height,x+1);
        function(root->right,height,x+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        //TreeNode* root1=root;
        int h=height(root);
        //cout<<h<<" ";
        function(root,h,1);
        return sum;
    }
};