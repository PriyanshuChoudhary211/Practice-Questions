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
    
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode *newNode= new TreeNode(val);
        TreeNode *parent=NULL,*curr=root;
        while(curr && curr->val>val)
        {
            parent=curr;
            curr=curr->right;
        }
        if(curr==NULL)
        {
            parent->right=newNode;
        }
        else if(parent==NULL)
        {
            newNode->left=curr;
            return newNode;
        }
        else
        {
            newNode->left=curr;
            parent->right=newNode;
        }
        return root;
        
    }
};