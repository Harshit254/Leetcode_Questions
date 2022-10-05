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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root==NULL) return NULL;
        if(depth==1)
        {
            TreeNode* root2=new TreeNode(val);
            root2->left=root;
            return root2;
        }
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        while(!q.empty())
        {
            level++;
            int x=q.size();
            for(int i=0;i<x;i++)
            {
                 TreeNode* node=q.front();
                 q.pop();
                if(level!=depth-1)
                {
                    if(node->left)
                    {
                        q.push(node->left);
                    }
                    if(node->right)
                    {
                        q.push(node->right);
                    }
                }
                else
                {
                    TreeNode* Left=new TreeNode(val);
                    TreeNode* Right=new TreeNode(val);
                    Left->left=node->left;
                    node->left=Left;
                    Right->right=node->right;
                    node->right=Right;
                }
            }
        }
        return root;
        
    }
};