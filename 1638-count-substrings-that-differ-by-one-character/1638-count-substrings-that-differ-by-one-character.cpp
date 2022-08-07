class Solution {
public:
    int countSubstrings(string s, string t) {
        int diff=0,ans=0;
        for(int i=0;i<s.length();i++)
        {
            for(int j=0;j<t.length();j++)
            {
                int x=i,y=j;
                diff=0;
                while(x!=s.length() && y!=t.length())
                {
                    if(s[x]!=t[y])
                    {
                        diff++;
                    }
                    if(diff==1) ans++;
                    if(diff==2) break;
                    x++;y++; 
                }
            }
        }
        return ans;
    }
};