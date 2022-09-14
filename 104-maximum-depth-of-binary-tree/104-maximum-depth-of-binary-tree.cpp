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
    int ans=INT_MIN;
    void func(TreeNode *root, int c)
    {
        
        if(!root || (root->left==NULL && root->right==NULL))
        {
                ans=max(ans,c);
                return;
        }
        if(root)
        {
            
            func(root->left,c+1);
            func(root->right,c+1);
        }
        
        return;
    }
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        func(root,1);
        return ans;
    }
};