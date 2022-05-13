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
    bool ch(TreeNode *root,int x)
    {
         if(root == NULL) return true;
            if(x!=root->val)
                return false;
            return ch(root->left,x)&& ch(root->right,x);
    }
    bool isUnivalTree(TreeNode* root) {
        int x = root->val;
        return ch(root,x);
       
        
    }
};