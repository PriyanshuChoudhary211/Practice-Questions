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
class BSTIterator {
public:
    vector<int>ino;
    TreeNode *temp;
    int i=0,j=i;
    void inorder(TreeNode *temp)
    {
        if(temp)
        {
            inorder(temp->left);
            ino.push_back(temp->val);
            inorder(temp->right);
        }
    }
    BSTIterator(TreeNode* root) {
        temp=root;
        inorder(temp);
    }
    
    int next() {
        return ino[i++];
    }
    bool hasNext() {
        if(i<ino.size()) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */