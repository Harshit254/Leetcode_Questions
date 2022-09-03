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
// class Solution {
// public:
//      Solution(){
//         ios::sync_with_stdio(0);
//         cin.tie(0);
//         cout.tie(0);
//     }
//     bool function(TreeNode* root)
//     {
//         if(root!=NULL && root->left==NULL && root->right==NULL)return true;
        
//         return false;
//     }
//     TreeNode* removeLeafNodes(TreeNode* root, int target) {
//         if(root==NULL)
//         {
//             return NULL;
//         }
//         root->left=removeLeafNodes(root->left,target);
//         root->right=removeLeafNodes(root->left,target);
//         if(function(root))
//         {
//             if(root->val==target)
//             {
//                 return NULL;
//             }
//         }
//         return root;
//     }
// };


class Solution {
public:
    
//     Solution(){
//         ios::sync_with_stdio(0);
//         cin.tie(0);
//         cout.tie(0);
//     }
    
    bool isLeaf(TreeNode* root){
        
        return root!=NULL and root->left==NULL and root->right==NULL;
        
    }
    
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        
        if(root==NULL) return NULL;
        root->left = removeLeafNodes(root->left,target);
        root->right = removeLeafNodes(root->right,target);
        if(isLeaf(root)){
            if(root->val==target){
                
                return NULL;
            }
        }
        
        return root;
    }
};