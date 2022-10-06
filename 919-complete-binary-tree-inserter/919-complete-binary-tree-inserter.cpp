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
class CBTInserter {
public:
    queue<TreeNode*>q;
    TreeNode *start=NULL;
    CBTInserter(TreeNode* root) {
        start=root;
        q.push(root);
        while(1)
        {
            auto it=q.front();
            if(it->left==NULL) break;
            if(it->right==NULL) 
            {
                q.push(it->left);
                break;    
            }
            q.push(it->left);
            q.push(it->right);
            q.pop();          
        }
    }
    int insert(int val) {
        TreeNode *newNode=new TreeNode(val);
        q.push(newNode);
        auto it =q.front(); 
        if(it->left==NULL) it->left=newNode;
        else if(it->right==NULL) 
        {
            it->right=newNode;
            q.pop();
        }
        return it->val;
    }
    
    
    TreeNode* get_root() {
        return start;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */