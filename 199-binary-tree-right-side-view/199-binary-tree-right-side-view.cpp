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
    vector<int> rightSideView(TreeNode* root) {
        // vector<vector<int>a;
        vector<int>ans;
        queue<TreeNode *>q;
        if(root==NULL) return ans;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            int i=0;
            vector<int>temp;
            while(i<n){
                TreeNode *t = q.front();
                q.pop();
                temp.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
                i++;
            }
            int x=temp[temp.size()-1];
            ans.push_back(x);  
        }
        return ans;
    }
};