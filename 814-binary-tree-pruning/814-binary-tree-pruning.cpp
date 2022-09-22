/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
};
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* check(TreeNode *root)
    {
        if(root)
        {
               
            root->left=check(root->left);
            root->right=check(root->right);
            if(root->val==0 && root->left==NULL && root->right==NULL)
            {
                  delete(root);
                  return NULL;
                  
            }  
        }
        return root;
    }
    TreeNode* pruneTree(TreeNode* root) {
        return check(root);
    }
};