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
    int sumOfNodes(TreeNode *root)
    {
        if(root == NULL)
             return 0;
         return root->val + sumOfNodes(root->left) + sumOfNodes(root->right);     
    }
    int sums(TreeNode *root,int sum)
    {
        if(root == NULL)
            return 0;
        if(root)
        {
           int left = sumOfNodes(root->left);
           int right = sumOfNodes(root->right);
            int diff=abs(left-right);
            sum+=diff;
           return sum+sums(root->left,0)+sums(root->right,0);
            
        }
        return sum;
    }
    int findTilt(TreeNode* root) {
        int sum = 0;
        if(root==NULL)
            return 0;
        return sums(root,0);
    }
};