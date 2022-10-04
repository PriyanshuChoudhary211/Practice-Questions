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
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        map<int,pair<int,int>>mp;
        map<int,int>r_check;
        int n=d.size();
        for(int i=0;i<n;i++)
        {
            if(r_check.find(d[i][0])==r_check.end())
            {
                r_check[d[i][0]]=0;
            }
            r_check[d[i][1]]=1;
        }
        for(int i=0;i<n;i++)
        {
            if(d[i][2]==1)
                mp[d[i][0]].first=d[i][1];
            else
                mp[d[i][0]].second=d[i][1];

        }
//         for(auto it:mp)
//             cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
        
//         for(auto it:r_check)
//             cout<<it.first<<" "<<it.second<<endl;
        int r=0;
        for(auto it:r_check)
             if(it.second==0)
                 r=it.first;
        //cout<<r<<endl;
        TreeNode *root=new TreeNode(r);
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty())
        {   
            auto f=q.front();
            q.pop();
            auto it=mp[f->val];
            f->left=it.first?new TreeNode(it.first):NULL;
            if(f->left) q.push(f->left);
            f->right=it.second?new TreeNode(it.second):NULL;
            if(f->right) q.push(f->right);
        }
        
        return root;
    }
};