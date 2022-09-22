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
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        if(root->left)
        {
            TreeNode *temp=root->left;
            root->left=NULL;
            TreeNode* temp2=root->right;
            root->right=temp;
            while(temp->right)
                temp=temp->right;
            temp->right=temp2;
        }
        flatten(root->right);
    }
};