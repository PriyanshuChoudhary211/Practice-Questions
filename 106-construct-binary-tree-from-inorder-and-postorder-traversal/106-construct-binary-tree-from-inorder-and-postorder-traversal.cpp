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
        TreeNode *root=new TreeNode(po[epo]);
        auto it=find(in.begin()+sin,in.begin()+ein,po[epo]);
        int y=it-in.begin();
        root->left = create(in,po,sin,y-1,spo,spo+y-sin-1);
        root->right = create(in,po,y+1,ein,spo+y-sin,epo-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& po) {
        int ein=in.size()-1;
        int epo=po.size()-1;
        int sin=0;
        int spo=0;
        return create(in,po,sin,ein,spo,epo);
    }
};