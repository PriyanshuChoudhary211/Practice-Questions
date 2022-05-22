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
    TreeNode *insert(TreeNode*root, int val)
    {
        if(root == NULL)
            return new TreeNode(val);
        if(root->left == NULL && root->right == NULL)
        {
            if(root->val < val)
            {
                root->right = new TreeNode(val);
                return root;
            }
            else 
                root->left = new TreeNode(val);
            return root;
        }
        
            if(root->val>val)
            {
                root->left = insert(root->left,val);
            }
            else
                root->right = insert(root->right,val);
    
           return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return insert(root,val);
    }
};