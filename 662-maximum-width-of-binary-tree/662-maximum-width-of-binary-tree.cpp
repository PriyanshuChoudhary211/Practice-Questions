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
  

  int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>>q;
      // vector<vector<int>>ans;
      int maxi=INT_MIN;
      int ind=0;
        q.push({root,ind});
       while(!q.empty())
       {
           int min=q.front().second;
           int x=q.size();
           int i=0;
           vector<int>temp;
           
           while(i<x)
           {
               auto it=q.front();
               q.pop();
               temp.push_back(it.second);
               if(it.first->left) q.push({it.first->left,2*(it.second-min)+1});
               if(it.first->right) q.push({it.first->right,2*(it.second-min)+2});
               i++;
           }
           int n=temp.size();
           if(maxi<(temp[n-1]-temp[0]+1))
              maxi=temp[n-1]-temp[0]+1;
       }
      return maxi;
           
    }
};