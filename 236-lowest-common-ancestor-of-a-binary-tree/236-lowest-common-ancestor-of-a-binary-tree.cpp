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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        map<TreeNode *, TreeNode *>mp;
        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty())
        {
            TreeNode *it =que.front();
            que.pop();
            if(it->left)
            {
                que.push(it->left);
                mp[it->left]=it;
             //   if(mp[it->left]==q)break;
            }
            if(it->right)
            {
                que.push(it->right);
                mp[it->right]=it;
                //if(mp[it->right]==q)break;
            }
        }
        vector<int>ans;
        ans.push_back(q->val);
        while(mp.find(q)!=mp.end())
        {
            ans.push_back(mp[q]->val);
            q=mp[q];
        }
        TreeNode *i=p;
        while(find(ans.begin(),ans.end(),i->val)==ans.end())
        {
            i=mp[i];
        }
        return i;
        
    }
};