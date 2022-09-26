/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
         queue<TreeNode *>q;
        q.push(root);
        string ans="";
        while(!q.empty())
        {
            TreeNode *it=q.front();
            q.pop();
            if(it==NULL) ans+='n',ans+=',';
            else{
            ans+=to_string(it->val);
            ans+=',';
            }
            if(it)
                if(it->left) q.push(it->left);
                else q.push(NULL);
            if(it)
                if(it->right) q.push(it->right);
                else q.push(NULL);
        }
        //cout<<ans;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
         TreeNode *root;
        queue<TreeNode*>q;
        int i=0;
        string val="";
        while(data[i]!=',')
        {
            val+=data[i];
            i++;
        }
        i++;
        if(val=="n") return NULL;
        root=new TreeNode(stoi(val));
        q.push(root);
        while(!q.empty())
        {
           TreeNode *it=q.front();
            q.pop();
            string val="";
             while(data[i]!=',')
            {
                val+=data[i];
                i++;
            }
            i++;
            if(val=="n") it->left=NULL;
            else{
                 it->left=new TreeNode(stoi(val));
                q.push(it->left);
            }
            string val2="";
             while(data[i]!=',')
            {
                val2+=data[i];
                i++;
            }
            i++;
            if(val2=="n") it->right=NULL;
            else{
                 it->right=new TreeNode(stoi(val2));
                 q.push(it->right);
            }
        }       
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;