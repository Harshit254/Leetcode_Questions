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
        int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        vector<int> r = getSumAndNode(root,ans); 
        return ans;
    }
    
    vector<int> getSumAndNode(TreeNode* root, int &ans){
        if(root==NULL){
            vector<int> temp {0,0};
            return temp;
        }
        vector<int> l = getSumAndNode(root->left,ans);
        vector<int> r = getSumAndNode(root->right,ans);

        int sum = l[0]+r[0]+root->val;
        int nodes = l[1]+r[1]+1;
        
        if(sum/nodes == root->val) ans++;
        
        return vector<int>{sum,nodes};
    }
};