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
    string num;
// functn to convert binary to decimal:
    void bin_to_dec(string s){
        int a=0,n=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]){
                n+=pow(2,a);
            }
            a++;
        }
        sum+=n;
    }
// inorder traversal:
    bool inorder(TreeNode* root){
        if(root==NULL) return false;
        if(root->left==NULL && root->right==NULL){
            num+=root->val;
            bin_to_dec(num);
            return true;
        }
        num+=root->val;
        
        if(inorder(root->left)) num.erase(num.end()-1);
        if(inorder(root->right)) num.erase(num.end()-1);
        return true;
    }
    int sumRootToLeaf(TreeNode* root) {
        inorder(root);
        return sum;
    }
};