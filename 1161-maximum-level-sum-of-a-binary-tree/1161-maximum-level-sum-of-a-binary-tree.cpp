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
    int maxLevelSum(TreeNode* root) {
        int level=1,f_level=0,sum=root->val,maxi=INT_MIN;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            sum=0;
            int x=q.size();
            for(int i=0;i<x;i++)
            {
                auto it=q.front();
                q.pop();
                sum+=it->val;
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);  
            }
            if(sum>maxi)
            {
                maxi=sum;
                f_level=level;
            }   
            level++;
        }
        return f_level;   
    }
};