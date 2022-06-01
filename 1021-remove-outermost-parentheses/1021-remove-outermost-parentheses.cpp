class Solution {
public:
    string removeOuterParentheses(string s2) {
        string ans="";
        stack<char>s;
        for(int i=0;i<s2.length();i++)
        {
            if(s.empty() && s2[i]=='(')
            {
                s.push('(');
            }
            else if(s.size()>0 && s2[i]=='(')
            {
                s.push('(');
                ans+='(';
            }
            else if(s.size()>1 && s2[i]==')')
            {
                s.pop();
                ans+=')';
            }
            else s.pop();
        }
        return ans;
    }
};