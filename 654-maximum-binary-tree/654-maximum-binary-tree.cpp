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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0)
            return NULL;
        int x = (*max_element(nums.begin(),nums.end()));
        TreeNode *root = new TreeNode(x);
        vector<int>v1,v2;
        int i = 0;
        while(nums[i]!=x)
        {
            v1.push_back(nums[i++]);            
        }
        i++;
        while(i<nums.size())
        {
            v2.push_back(nums[i++]);
        }

        root->left = constructMaximumBinaryTree(v1);
        root->right = constructMaximumBinaryTree(v2);
        
        return root;
    }
};