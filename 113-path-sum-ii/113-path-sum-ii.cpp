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
    void fun(TreeNode *root,vector<vector<int>>&ans,vector<int> &a,int s)
    {
        if(root==NULL)
            return;
        if(root!=NULL)
        {
            a.push_back(root->val);
        }
        if(root->left == NULL && root->right==NULL)
        {
            if(accumulate(a.begin(),a.end(),0)==s)
               ans.push_back(a);
            return ;
        }
        if(root->left) 
        {
            fun(root->left,ans,a,s);
            a.pop_back();
        }
        if(root->right)
        {
            fun(root->right,ans,a,s);
            a.pop_back();
        }  
        return;
     }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
         
        vector<vector<int>> ans;
           if(root== NULL)
            return ans;
        vector<int>a;
        fun(root,ans,a,targetSum);
        return ans;
    }
};