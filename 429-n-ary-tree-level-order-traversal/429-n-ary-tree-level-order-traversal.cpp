/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>>ans;
        if(root == NULL)
            return ans;
          vector<int>a;
        queue<Node *>q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty())
        {
           Node *temp = q.front();
            q.pop();
            if(temp == NULL)
            {
                ans.push_back(a);
                a.clear();
                if(q.empty())
                {
                    return ans;
                }
                q.push(NULL);
            }
            else
            {
                a.push_back(temp->val);
                for(auto i: temp->children)
                {
                    q.push(i);
                }
            }
        } 
        return ans;
        
    }
};