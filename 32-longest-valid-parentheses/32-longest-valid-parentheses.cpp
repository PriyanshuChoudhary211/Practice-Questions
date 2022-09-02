class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char>st;
        stack<int>ind;
        ind.push(-1);
        int maxi=0;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push(s[i]);
                ind.push(i);
            }
            else
            {
                if(!st.empty() && st.top()=='(')
                {
                    st.pop();
                    ind.pop();
                    maxi=max(maxi,i-ind.top());

                }
                else
                {
                    ind.push(i);
                }
            }
        }
        return maxi;

    }
};