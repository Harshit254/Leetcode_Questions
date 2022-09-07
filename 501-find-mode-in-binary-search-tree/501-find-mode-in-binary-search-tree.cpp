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
    map<int,int> m;
    vector<int> findMode(TreeNode* root) {
      tree(root);
        vector<int> out;
        int ans = INT_MIN;
      for(auto i:m){
          ans = max(ans,i.second); 
      }
      for(auto i :m){
          if(i.second == ans)out.push_back(i.first);
      } 
        return out;
    }
    void tree(TreeNode* root){
        if(root==NULL) return;
        if(!m[root->val])m[root->val]=1;
        else m[root->val]++;
        tree(root->left);
        tree(root->right);
    }
};