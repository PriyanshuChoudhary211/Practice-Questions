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
      TreeNode *create(vector<int>& in, vector<int>& po,int sin,int ein, int spo,int epo)
    {
        if(sin==ein) return new TreeNode(in[sin]);
        if(sin>ein || spo>epo) return NULL;
        TreeNode *root=new TreeNode(po[spo]);
        auto it=find(in.begin()+sin,in.begin()+ein,po[spo]);
        int y=it-in.begin();
        root->left = create(in,po,sin,y-1,spo+1,spo+y-sin);
        root->right = create(in,po,y+1,ein,spo+y-sin+1,epo);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
         int ein=in.size()-1;
        int epo=pre.size()-1;
        int sin=0;
        int spo=0;
        return create(in,pre,sin,ein,spo,epo);
    }
};