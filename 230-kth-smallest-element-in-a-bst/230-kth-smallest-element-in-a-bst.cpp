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
    
    int count(TreeNode *root)
    {
        if(root==NULL) return 0;
        int l=count(root->left);
        int r=count(root->right);
        return l+r+1;
    }
    int check(TreeNode *root,int k)
    {
        int c=count(root->left);
        if(k==c+1) return root->val;
        if(c>=k) return check(root->left,k);
        if(c<k)return check(root->right,k-c-1);
        
      return -1;
    }
    int kthSmallest(TreeNode* root, int k) {
        
        return check(root,k);
    }
};