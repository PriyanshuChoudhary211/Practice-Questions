class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>pu,po;
        int n = popped.size();
        for(int i = n-1;i>=0;i--)
        {
            po.push(popped[i]);
        }
        for(auto i : pushed)
        {
            pu.push(i);
            while(!po.empty() && !pu.empty() && po.top() == pu.top())
            {
                po.pop();
                pu.pop();
            }
            
            
        }
        if(!po.empty() || !pu.empty())
            return false;
        return true;
    }
};