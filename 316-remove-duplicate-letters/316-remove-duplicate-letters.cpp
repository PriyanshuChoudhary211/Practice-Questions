class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char,int>mp;
        stack<char>st;
        string ans="";
        int temp[26]={0};
        for(auto it:s)
        {
            mp[it]++;
        }
        for(auto i:s)
        {
            if(st.empty() || (i>st.top() && temp[i-97]==0))
            {
                st.push(i);
                temp[i-97]=1;
                mp[i]--;
            }
            
            else if(i<st.top())
            {                
                    if(temp[i-97]==0)
                    {
                        while(!st.empty() && i<st.top() && mp[st.top()]>0)
                        {
                            temp[st.top()-97]=0;
                            st.pop();
                        }
                         st.push(i);
                         temp[i-97]=1;
                         mp[i]--;
                    }
                  else
                      mp[i]--;
            }
            else if(i==st.top())
                mp[st.top()]--;
        }
        while(!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
        
       
    }
};