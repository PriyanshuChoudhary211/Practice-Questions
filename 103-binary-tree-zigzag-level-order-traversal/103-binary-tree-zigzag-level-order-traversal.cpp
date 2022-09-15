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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
     vector<vector<int>>ans2; 

        if(root == NULL) return ans2;
        queue<TreeNode* >q;
       
        q.push(root);
        while(!q.empty())
        { 
            vector<int>ans;
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                TreeNode* x=q.front();
                q.pop();
                ans.push_back(x->val);
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
            ans2.push_back(ans);
        }
        for(int i=0;i<ans2.size();i++)
        {
            if(i%2==1)
            {
                reverse(ans2[i].begin(),ans2[i].end());
            }
        }
        return ans2;
    }
    
};