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
void mindiff(TreeNode* root,vector<int>&v){
if(root==NULL){
return;
}
mindiff(root->left,v);
v.push_back(root->val);
mindiff(root->right,v);
}

int getMinimumDifference(TreeNode* root) {
    int cheak=INT_MAX;
    vector<int> v;
    mindiff(root,v);
    for(int i=1;i<v.size();i++){
        cheak=min(cheak,abs(v[i]-v[i-1]));
    }
    return cheak;
}
};