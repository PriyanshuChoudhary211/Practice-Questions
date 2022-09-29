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
    TreeNode *lca(TreeNode *root, TreeNode *root1,TreeNode *root2)
    {
        if(root==NULL) return root;
        if(root==root1 || root==root2) return root;
        TreeNode *l=lca(root->left,root1,root2);
        TreeNode *r=lca(root->right,root1,root2);
        
        if(l==NULL) return r;
        else if(r==NULL) return l;
        else return root;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        queue<TreeNode*>q;
        vector<TreeNode*>ans;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            ans.clear();
            for(int i=0;i<size;i++)
            {
                auto it=q.front();
                q.pop();
                ans.push_back(it);
            
                if(it->left)q.push(it->left);
                if(it->right)q.push(it->right);
            }
          
        }
        if(ans.size()==1) return ans[0];
        auto f=ans[0];
        auto l=ans[ans.size()-1];
        return lca(root,f,l);

    }
};