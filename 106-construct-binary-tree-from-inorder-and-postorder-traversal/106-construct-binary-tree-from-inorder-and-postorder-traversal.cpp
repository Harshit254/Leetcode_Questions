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
    TreeNode* buildTree(vector<int>& a,int &i, vector<int>& b,int l,int r) {
		if(l>r)return NULL;
		TreeNode *node=new TreeNode(a[i]);
		i--;
		if(l==r)
			return node;
		int j=l;
		while(b[j]!=a[i+1])j++;
        node->right=buildTree(a,i,b,j+1,r);
		node->left=buildTree(a,i,b,l,j-1);
		return node;
	}
	TreeNode* buildTree( vector<int>& inorder,vector<int>& postorder) {
		int i=postorder.size()-1;
		return buildTree(postorder,i,inorder,0,inorder.size()-1);
	}
};