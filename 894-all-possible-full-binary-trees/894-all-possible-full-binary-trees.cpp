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
    vector<TreeNode*>helper(int n)
    {
        if(n==1)
        {
            TreeNode *root = new TreeNode(0);
            vector<TreeNode*>b;
            b.push_back(root);
            return b;
        }
        vector<TreeNode *>ans;
        for(int i = 1; i<n;i+=2)
        {
            vector<TreeNode*>le = helper(i);
            vector<TreeNode*>ri = helper(n-i-1);
            for(auto l:le)
            {
                for(auto r : ri)
                {
                    TreeNode *roo = new TreeNode(0);
                    roo->left = l;
                    roo->right = r;
                    ans.push_back(roo);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        return helper(n);
    }
};