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
    void func(TreeNode *root,vector<pair<int,pair<int,int>>>&ans,int i,int r)
    {
        if(root==NULL) return;
         ans.push_back({i,{r,root->val}});
         if(root->left) func(root->left,ans,i-1,r+1);
         if(root->right) func(root->right,ans,i+1,r+1);
        
        return;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<pair<int,pair<int,int>>>ans;
        func(root,ans,0,0);
        // for(auto it:ans)
        //     cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<" "<<endl;
        sort(ans.begin(),ans.end()); 
        vector<vector<int>>a;
        vector<int>temp;
        temp.push_back(ans[0].second.second);
        for(int i=1;i<ans.size();i++)
        {
            if(ans[i-1].first==ans[i].first)
                temp.push_back(ans[i].second.second);
            else
            {
                a.push_back(temp);
                temp.clear();
                temp.push_back(ans[i].second.second);
            }
        }
        a.push_back(temp);
        return a;
    }
};