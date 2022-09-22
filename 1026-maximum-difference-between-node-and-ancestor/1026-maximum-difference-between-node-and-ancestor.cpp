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
    int ma=0;
    void check(TreeNode *root, int maxi,int mini)
    {
        if(root)
        {
            mini=min(mini,root->val);
            maxi=max(maxi,root->val);
            ma=max(maxi-mini,ma);
            check(root->left,maxi,mini);
            check(root->right,maxi,mini);
            
        }
        return;
    }
    int maxAncestorDiff(TreeNode* root) {
        check(root,INT_MIN,INT_MAX);
        return ma;
    }
};