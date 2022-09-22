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
    
    int c=0;
    void check(TreeNode *root,int maxi)
    {
        
        if(root)
        {
            if(root->val>=maxi) c++;
            maxi=max(maxi,root->val);
            check(root->left,maxi);
            check(root->right,maxi);
            
        }
        return;
    }
    int goodNodes(TreeNode* root) {
        check(root,INT_MIN);
        return c;
    }
};