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
    vector<TreeNode*> allPossibleFBT(int n) {
        if (map.find(n) != map.end())   return map[n];
        vector<TreeNode*> res;
        if (n == 1) {
            res.push_back(new TreeNode(0));
            return res;
        }
        for (int i = 1; i < n; i++) {
            int nodes_left  = i;
            int nodes_right = n - 1 - i;
            TreeNode* newroot = new TreeNode(0);
            vector<TreeNode*> left_options  = allPossibleFBT(nodes_left);
            vector<TreeNode*> right_options = allPossibleFBT(nodes_right);
            for (int l = 0; l < left_options.size(); l++) {
                for (int r = 0; r < right_options.size(); r++) {
                    TreeNode* newroot = new TreeNode(0);
                    newroot -> left  = left_options[l];
                    newroot -> right = right_options[r];
                    res.push_back(newroot);
                }
            }
        }
        return map[n] = res;
    }
unordered_map<int, vector<TreeNode*>> map;
};