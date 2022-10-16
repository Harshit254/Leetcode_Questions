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
    TreeNode* sortedArrayToBST(vector<int>& nums)
        {
                   
        return CreateTree(0, nums.size() - 1, nums);
    }
    
    TreeNode* CreateTree(int left, int right,vector<int>&nums)
    {
            if(left > right)
                return NULL;
        
            int midIndex = (right + left) / 2;
            TreeNode* node = new TreeNode(nums[midIndex]);
            
            node->left = CreateTree(left, midIndex - 1, nums);
            node->right = CreateTree(midIndex + 1, right, nums);
        
            return node;     
        
    }
};