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
    string st(vector<int>&a)
    {
        string s = "";
        int n = a.size();
        for(int i = 0; i<n-1;i++)
        {
            s+=to_string(a[i])+"->";
        }
        s+=to_string(a[n-1]);
        return s;
    }
        
    void fun(TreeNode *root,vector<string>&ans,vector<int> &a)
    {
        if(root==NULL)
            return;
        if(root!=NULL)
        {
            a.push_back(root->val);
        }
        if(root->left == NULL && root->right==NULL)
        {
            string s = st(a);
            ans.push_back(s);
            return ;
        }
        if(root->left) 
        {
            fun(root->left,ans,a);
            a.pop_back();
        }
        if(root->right)
        {
            fun(root->right, ans, a);
            a.pop_back();
        }  
        return;
     }
    vector<string> binaryTreePaths(TreeNode* root) {
     
        vector<string> ans;
           if(root== NULL)
            return ans;
        vector<int>a;
        fun(root,ans,a);
        return ans;
    }
};