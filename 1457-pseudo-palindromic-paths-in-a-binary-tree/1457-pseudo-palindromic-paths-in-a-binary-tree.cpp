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
    void function(TreeNode* root,vector<int>&temp)
    {
        if(root==NULL) return;
        
        temp[root->val]++;
        function(root->left,temp);
        function(root->right,temp);
        if(root->left==NULL && root->right==NULL)
        {
            int flag=0;
            for(auto i:temp)
            {
                if(i%2!=0) flag++;
            }
            
            if(flag==0 || flag==1) count++;
        }
        temp[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>temp(10,0);
        function(root,temp);
        return count;
        
    }
};