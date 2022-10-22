class Solution {
public:
    string decodeString(string s) {
        vector<int>c;
        stack<string>st;
        string str="";
        for(int i = 0 ; i<s.length();i++)
        {
            if(s[i]>='0' && s[i]<='9')
                str+=s[i];
            else if(s[i]=='[')
            {
                c.push_back(stoi(str));
                str.clear();
                string temp ="";
                temp += s[i];
                st.push(temp);
                temp.clear();
            }
            else if(s[i]>='a' && s[i]<='z')
            {
                string temp ="";
                temp += s[i];
                st.push(temp);
                temp.clear();
            }
            else if(s[i]==']')
            {
               string str1="";
                while(!st.empty() && st.top()!="[")
                {
                    str1 = st.top()+str1;
                    st.pop();
                }
                st.pop();
                int t = c[c.size()-1];
                c.pop_back();
                while(t--)
                {
                    st.push(str1);
                }
            }
        }
        string ans = "";
        while(!st.empty())
        {
            ans=st.top() + ans;
            st.pop();
        }
        return ans;
        
    }
};