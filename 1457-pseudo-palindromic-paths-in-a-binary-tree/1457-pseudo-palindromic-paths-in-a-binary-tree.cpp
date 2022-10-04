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
    int ans=0;
    map<int,int>mp;
    int odd=0;
    void func(TreeNode *root)
    {
        if(root==NULL) return;
         mp[root->val]++;  
         if(mp[root->val]%2) odd++;
         else odd--;
        if(root->left==NULL && root->right==NULL)
        {
            if(odd<2) ans++;
        }
        func(root->left);
        func(root->right);
        mp[root->val]--;
        if(mp[root->val]%2) odd++;
        else odd--;
    
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        map<int,int>mp;
         func(root);
        return ans;
    }
};