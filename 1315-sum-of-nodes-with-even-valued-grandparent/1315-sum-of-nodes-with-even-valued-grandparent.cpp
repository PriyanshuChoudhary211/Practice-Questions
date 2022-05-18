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
    int sumEvenGrandparent(TreeNode* root) {
         int s = 0;
        if(root == NULL)
            return s;
        
        if(root->val % 2 == 0)
        {
             s += root->left  && root->left->left?root->left->left->val:0;
             s += root->left  && root->left->right?root->left->right->val:0;
             s += root->right && root->right->left?root->right->left->val:0;
             s += root->right && root->right->right?root->right->right->val:0;  
        }
        s += sumEvenGrandparent(root->left);
        s += sumEvenGrandparent(root->right);
        return s;
    }
};