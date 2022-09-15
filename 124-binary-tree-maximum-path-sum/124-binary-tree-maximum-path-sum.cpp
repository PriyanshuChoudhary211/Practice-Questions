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
    int maxsum(TreeNode* root)
    {
        if(root==NULL) return 0;
        int l=root->val+maxsum(root->left);
        int r=root->val+maxsum(root->right);
        //int x=l+r-root->val;
        return max(l,max(r,root->val));
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return -1e9;
        int p1=maxsum(root->left);
        int p2=maxsum(root->right);
        int x=max(max(root->val,root->val+p1+p2),max(root->val+p1,root->val+p2));
        int l=maxPathSum(root->left);
        int r=maxPathSum(root->right);
        return max(l,max(r,x));
    }
};