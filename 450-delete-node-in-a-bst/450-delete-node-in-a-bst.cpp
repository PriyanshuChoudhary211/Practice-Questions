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
    TreeNode* isuc(TreeNode *root)
    {
        if(root==NULL) return NULL;
        root=root->right;
        while(root && root->left!=NULL)
        {
            root=root->left;
        }
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key && root->left == NULL && root->right == NULL)
        {
            delete(root);
            return NULL;
        }
        if(root->val>key) root->left=deleteNode(root->left,key);
        else if(root->val<key) root->right=deleteNode(root->right,key);
        else
        {
            TreeNode *next=isuc(root);
            if(next==NULL) return root->left;
            root->val=next->val;
            root->right=deleteNode(root->right,next->val);
        }
        return root;
    }
};