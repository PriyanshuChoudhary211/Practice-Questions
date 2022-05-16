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
    int maxi = INT_MIN;
    int depth(TreeNode *root)
    {
       if(root == NULL)
           return 0;
        
            int left = 1+depth(root->left);
            int right = 1+depth(root->right);
            return max(left,right);
    }
    void fun(TreeNode *root)
    {
        if(root == NULL)
            return;
        int x = depth(root->left)+depth(root->right);
        maxi= max(maxi,x);
        fun(root->left);
        fun(root->right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
         fun(root);
        return maxi;
    }
};