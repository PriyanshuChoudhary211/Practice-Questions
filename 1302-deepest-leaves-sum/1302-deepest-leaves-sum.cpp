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
    int s=0;
    int depth(TreeNode* t)
    {
        if(t == NULL)
            return 0;
        int l = 1+depth(t->left);
        int r = 1+depth(t->right);
        return max(l,r);
    }
    void sum(TreeNode *r, int x)
    {
        if(r == NULL)
           return;
        if(x == 1)
        {
            s += r->val;
            return;
        }
        sum(r->left,x-1);
        sum(r->right,x-1);
    }
    int deepestLeavesSum(TreeNode* root) {
        int x = depth(root);
        sum(root,x);
        return s;
    }
};