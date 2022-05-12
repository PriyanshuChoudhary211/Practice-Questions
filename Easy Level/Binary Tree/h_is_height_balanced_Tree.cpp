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
 
class Solution {
public:
    int minDepth(TreeNode* root) {
         if(root == NULL) return 0;
        int l = 1+minDepth(root->left);
        int r = 1+minDepth(root->right);
        return max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL)return true;
       
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        if(abs(l-r)>1)
            return false;
        
        return true && (isBalanced(root->left) && isBalanced(root->right));        
    }
};


*/
