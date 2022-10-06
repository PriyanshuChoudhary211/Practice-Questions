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
    map<int,int>mp;
    int postorder(TreeNode *root)
    {   
        if(!root) return 0;
        
        int l=postorder(root->left);
        int r=postorder(root->right);
        int s=l+r+root->val;
        mp[s]++;
        return s;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int x=postorder(root);
        int maxi=INT_MIN;
         vector<int>ans;
        for(auto it:mp)
        {
            maxi=max(maxi,it.second);                
        }
        for(auto it:mp)
        {
            if(maxi==it.second)
                ans.push_back(it.first);
        }
        return ans;
    }
};