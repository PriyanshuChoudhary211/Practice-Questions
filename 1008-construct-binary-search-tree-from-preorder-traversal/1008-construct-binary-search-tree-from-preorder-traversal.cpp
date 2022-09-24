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
    TreeNode *check(vector<int>&preorder,int l,int r)
    {
        if(l>r) return NULL;
        TreeNode *root=new TreeNode(preorder[l]); 
        auto it=lower_bound(preorder.begin()+l+1,preorder.begin()+r+1,preorder[l])-preorder.begin();
        int ind=it-1;
            root->left=check(preorder,l+1,ind);
            root->right=check(preorder,ind+1,r);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return check(preorder,0,preorder.size()-1);
    }
};