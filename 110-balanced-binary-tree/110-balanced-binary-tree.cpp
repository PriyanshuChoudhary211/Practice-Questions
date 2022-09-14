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
    int maxDepth(TreeNode *root)
    {
        if(!root) return 0;
        return max(1+maxDepth(root->left),1+maxDepth(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int diff=abs(maxDepth(root->left)-maxDepth(root->right));
        if(diff<=1)
        {
            return isBalanced(root->left) && isBalanced(root->right);
        }   
        return false;
    }
    
    
};