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
    int md(TreeNode*root)
    {
        if(!root) return 0;
        return max(1+md(root->left),1+md(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int x=md(root->left)+md(root->right);
        int l=diameterOfBinaryTree(root->left);
        int r=diameterOfBinaryTree(root->right);   
       return max(l,max(r,x));
    }
};