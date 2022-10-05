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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
             TreeNode *newNode1 = new TreeNode(val);
             newNode1->left=root;
            return newNode1;
        }
        queue<TreeNode*> q;
        int d=1;
        q.push(root);
        while(d<depth-1)
        {
            int x=q.size();
            while(x--)
            {
                auto it=q.front();
                q.pop();
                if(it->left)q.push(it->left);
                if(it->right)q.push(it->right);
            }
            d++;
        } 
        while(!q.empty())
        {
            TreeNode *newNode1 = new TreeNode(val);
            TreeNode *newNode2 = new TreeNode(val);
            auto it=q.front();
            q.pop();
            newNode1->left=it->left;
            newNode2->right=it->right;
            it->left=newNode1;
            it->right=newNode2;
        }
        return root;
    }
};