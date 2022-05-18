/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* inorder(TreeNode* original, TreeNode* cloned, TreeNode* target)
    {
        if(original == NULL )
            return NULL;
        if(original == target)
            return cloned;
        TreeNode * p=inorder(original->left, cloned->left,target);
        if(p==NULL)
            return inorder(original->right, cloned->right,target);
        return p;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original == NULL)
            return NULL;
       return inorder(original, cloned, target);
    }
};