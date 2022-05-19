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
    TreeNode *bst(vector<int>&A , int &i, int bound)
    {
//         static int idx = 0;
         
//         if(idx == pre.size())
//             return NULL;
//         if(s>e)
//             return NULL;
//         int curr = pre[idx];
//         TreeNode *root = new TreeNode(curr);
//          idx++;
        
//         if(s==e)
//             return root;
//          int pos = -1;
//         for(int i = s; i<=e;i++)
//         {
//             if(curr == ino[i])
//                 pos = i;
//         }
//         root->left = bst(pre,ino,s,pos-1);
//         root->right = bst(pre,ino,pos+1,e);
//         return root;

        if(i == A.size()||A[i]>bound)return NULL;
        TreeNode *root = new TreeNode(A[i++]);
        root->left = bst(A,i,root->val);
        root->right = bst(A,i,bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& a) {
       // vector<int>ino = preorder;
      //   sort(ino.begin(),ino.end());
         int i = 0;
      //   int idx = 0;
      //   int e = ino.size()-1;
      return bst(a,i,INT_MAX);
        
    }
};