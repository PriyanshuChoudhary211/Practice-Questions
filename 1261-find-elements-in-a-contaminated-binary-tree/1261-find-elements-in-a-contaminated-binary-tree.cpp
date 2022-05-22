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
class FindElements {
public:
    TreeNode *root;
    bool inorder2(int t,TreeNode *root2)
    {
        if(root2)
        {
            if(root2->val == t)
                return true;
             return inorder2(t,root2->left) || inorder2(t,root2->right);
        }
        else 
            return false;
    }
    void inorder(TreeNode *root)
    {
        if(root!=NULL)
        {
            if(root->left!=NULL)
            {
                root->left->val = 2 * root->val +1;
                
            }
            if(root->right != NULL)
                root->right->val = 2 * root->val +2;
            inorder(root->left);
            inorder(root->right);
        }
    }
    FindElements(TreeNode* root) {
       this->root = root;
        this->root->val = 0;
        inorder(this->root);
    }
    
    bool find(int target) {
        
        return inorder2(target,root);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */