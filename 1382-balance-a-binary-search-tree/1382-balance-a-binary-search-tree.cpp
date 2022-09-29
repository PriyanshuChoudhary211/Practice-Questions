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
    vector<int>ans;
    void inorder(TreeNode* root)
    {
        if(root)
        {
            inorder(root->left);
            ans.push_back(root->val);
            inorder(root->right);
        }
    }
    TreeNode* makeTree(int s,int e)
    {
        TreeNode *root=NULL;
        if(s>e) return NULL;
        if(s==e) return new TreeNode(ans[s]);
        int mid=(s+e)/2;
        root = new TreeNode(ans[mid]);
        root->left=makeTree(s,mid-1);
        root->right=makeTree(mid+1,e);
        
        return root;
        
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        int s=0,e=ans.size()-1;        
        return makeTree(s,e);
        
    }
};