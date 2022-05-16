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
    void fun(TreeNode *root,vector<int> &a,int s,bool &v)
    {
        if(root==NULL)
            return ;
        if(root!=NULL)
        {
            a.push_back(root->val);
        }
        if(root->left == NULL && root->right==NULL)
        {
            if(accumulate(a.begin(),a.end(),0)==s)
            {
                v = true;
                return;
            }
            
        }
        if(root->left) 
        {
            fun(root->left,a,s,v);
            a.pop_back();
        }
        if(root->right)
        {
            fun(root->right,a,s,v);
            a.pop_back();
        }  
     }
     bool hasPathSum(TreeNode* root, int targetSum) {
         
        
           if(root== NULL)
            return false;
        vector<int>a;
         bool v = false;
       fun(root,a,targetSum,v);
         return v;
        
    }
};
    