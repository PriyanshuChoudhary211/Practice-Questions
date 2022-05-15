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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        queue<TreeNode *>q;
        
        q.push(root);
        q.push(NULL);
        vector<int>a;
        while(!q.empty())
        {
            TreeNode *res = q.front();
            
            if(res != NULL)
            {
                a.push_back(res->val);
                if(res->left!=NULL)
                    q.push(res->left);
                if(res->right!=NULL)
                    q.push(res->right);
                q.pop();
            }
            if(res == NULL)
            {
                ans.push_back(a);
                a.clear();
                q.pop();
                if(q.empty())
                {
                    reverse(ans.begin(),ans.end());
                    return ans;
                }
                q.push(NULL);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};