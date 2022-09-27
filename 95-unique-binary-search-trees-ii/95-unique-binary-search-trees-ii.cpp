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
    TreeNode* insert(TreeNode* root,int n)
    {
        if(root==NULL) return new TreeNode(n);
        if(root->val<n) root->right=insert(root->right,n);
        else if(root->val>n) root->left=insert(root->left,n);
        return root;
    }
    TreeNode* createTree(vector<int>&arr)
    {
        TreeNode *root=NULL;
        for(int i=0;i<arr.size();i++)
        {
            root=insert(root,arr[i]);
        }
        return root;
    }
    bool isSimilar(TreeNode *a,TreeNode*b)
    {
        if(a==NULL && b==NULL) return true;
        if(a==NULL || b==NULL) return false;
        if(a->val != b->val) return false;
        bool l=isSimilar(a->left,b->left);
        bool r=isSimilar(a->right,b->right);
        return l && r;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<int>arr;
        vector<TreeNode*>ans;
        for(int i=1;i<=n;i++)
        {
            arr.push_back(i);
        }
        do
        {
            TreeNode *root=NULL;
            root=createTree(arr);
            int f=0;
            for(int i=0;i<ans.size();i++)
            {
                if(isSimilar(root,ans[i])==true)
                {f=1;break;}
            }
            if(f==0)
               ans.push_back(root);
        }while(next_permutation(arr.begin(),arr.end()));
        vector<TreeNode*>res;
        for(auto it:ans)
        {
            res.push_back(it);
        }
        return res;
    }
};