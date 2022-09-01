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
class FindElements {
    map<int,int> mp;
public:
    FindElements(TreeNode* root) {
        if(root)  root->val=0,mp[0]++;
        checkNumber(root);
    }
    
    bool find(int target) {
        return mp[target]>0; 
    }
    void checkNumber(TreeNode* root){
        if(!root) return ;
        if(root->left) root->left->val = root->val*2+1,mp[root->val*2+1]++;
        if(root->right) root->right->val = root->val*2+2,mp[root->val*2+2]++;
        checkNumber(root->left);
        checkNumber(root->right);
    }
};


/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */