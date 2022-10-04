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
    TreeNode* func(vector<int>& pre, vector<int>& pos,int s_pre,int e_pre,int s_pos,int e_pos)
    {
        if(s_pre==e_pre) return new TreeNode(pre[s_pre]);
        if(s_pre>e_pre) return NULL;
        TreeNode *root=new TreeNode(pos[e_pos]);
        int i=find(pos.begin(),pos.end(),pre[s_pre+1])-pos.begin();
        root->left=func(pre,pos,s_pre+1,s_pre+1+i-s_pos,s_pos,i);
        root->right=func(pre,pos,s_pre+2+i-s_pos,e_pre,i+1,e_pos-1);
        
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& postorder) {
     int s_pre=0,e_pre=pre.size()-1,s_pos=0,e_pos=postorder.size()-1;
     return func(pre,postorder,s_pre,e_pre,s_pos,e_pos);
    }
};