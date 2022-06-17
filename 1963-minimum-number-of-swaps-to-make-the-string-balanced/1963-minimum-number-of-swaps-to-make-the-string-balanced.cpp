class Solution {
public:
    int minSwaps(string s) {
        stack<int>st;
        int n = s.length();
        for(int i =0; i<n;i++)
        {
            if(st.empty()||s[i]=='[')
                st.push(s[i]);
            else if(s[i]==']' && st.top()=='[')
                st.pop();
                else 
            st.push(s[i]);
        }
        int c=st.size()/2;
        return (c+1)/2;
    }
};