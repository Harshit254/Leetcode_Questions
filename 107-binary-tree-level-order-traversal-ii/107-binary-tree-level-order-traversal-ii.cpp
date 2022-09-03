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
public: vector<vector<int>>res;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==NULL) return res;
        queue<TreeNode*>qu;
        qu.push(root);

        while(!qu.empty())
        {
            int n=qu.size();
             vector<int>ans;
            for(int i=0;i<n;i++)
            {
                TreeNode* node=qu.front();
                qu.pop();
                ans.push_back(node->val);
                if(node->left!=NULL)
                {
                    qu.push(node->left);
                }
                if(node->right!=NULL)
                {
                    qu.push(node->right);
                }
            }
            res.push_back(ans);
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};