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
class NodeValue
{
    public:
    int maxi,mini,sum;
    NodeValue(int m,int mi,int s)
    {
        maxi=m;
        mini=mi;
        sum=s;
    }
};
class Solution {
public:
    int m=0;
    NodeValue func(TreeNode *root)
    {
        if(root==NULL) return NodeValue(INT_MIN,INT_MAX,0);
        auto l=func(root->left);
        auto r=func(root->right);
        
        if(l.maxi<root->val && r.mini>root->val)
        {
            m=max(m,l.sum+r.sum+root->val);
            return NodeValue(max(r.maxi,root->val),min(l.mini,root->val),l.sum+r.sum+root->val); 
        }
        return NodeValue(INT_MAX,INT_MIN,max(l.sum,r.sum));
    }
    int maxSumBST(TreeNode* root) {
        auto it=func(root);
        if(it.sum<0) return 0;
        return m;
    }
};