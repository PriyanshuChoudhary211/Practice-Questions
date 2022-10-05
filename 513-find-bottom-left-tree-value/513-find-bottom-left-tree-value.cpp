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
    int maxiDepth=0,maxi=0;
    int value;
    void func(TreeNode *root)
    {
        if(root)
        {
            maxiDepth++;
            if(maxi<maxiDepth)
            {
                maxi=maxiDepth;
                value=root->val;
            }
            func(root->left);
            func(root->right);
            maxiDepth--;
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        func(root);
       return value;   
    }
};