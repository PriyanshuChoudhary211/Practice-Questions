class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>s1;
        string ans="";
        for(auto it :s)
        {
            if(!s1.empty() && s1.top() == it)
            {
                s1.pop();
            }
            else
            {
                s1.push(it);
            }
        }
        while(!s1.empty())
        {
            ans = s1.top()+ans;
            s1.pop();
        }
        
        return ans;
    }
};