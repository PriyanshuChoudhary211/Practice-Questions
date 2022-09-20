/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*>mp;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            if(it->left)
            {
                q.push(it->left);
                mp[it->left]=it;
            }
            if(it->right)
            {
                q.push(it->right);
                mp[it->right]=it;
            }
        }
     //   queue<TreeNode*>que;
        vector<int>visited(500);
        q.push(target);
        visited[target->val]=1;
        while(k>0)
        {
            
            int x=q.size();
            for(int i=0;i<x;i++)
            {
                auto it=q.front();
                q.pop();
                
                if(mp.find(it)!=mp.end() && visited[mp[it]->val]!=1)
                {
                    visited[mp[it]->val]=1;
                    q.push(mp[it]);
                }
                if(it->left && visited[it->left->val]!=1)
                {
                    visited[it->left->val]=1;
                    q.push(it->left);
                }
                if(it->right && visited[it->right->val]!=1)
                {
                    visited[it->right->val]=1;
                    q.push(it->right);
                }
            }
            k--;            
        }
        vector<int>ans;
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};