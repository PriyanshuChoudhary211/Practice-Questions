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
    int steps=0;
    int check(TreeNode *root)
    {
        if(root==NULL) return 0;
        int l=check(root->left);
        int r=check(root->right);
        steps+=abs(l)+abs(r);
        return l+r+root->val-1;
    }
    int distributeCoins(TreeNode* root) {
        int x = check(root);
        return steps;
    }
};