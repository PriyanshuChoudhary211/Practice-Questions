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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        TreeNode *t=NULL;
        queue<TreeNode *>q;
        
        
        q.push(root);
        q.push(NULL);
        double x=0,count=0;
        while(!q.empty())
        {
            TreeNode *res = q.front();
            if(res != NULL)
            {
                x+=res->val;
                count++;                
            }
            if(res == NULL)
            {
                ans.push_back(x/count);
                q.pop();

                if(q.empty())
                    return ans;
                q.push(NULL);
                x=0;count =0;
                continue;
            }
            q.pop();
            if(res->left!=NULL)           
              q.push(res->left);
            if(res->right!=NULL)
                q.push(res->right);
                   
            
        }
        return ans;
    }
};