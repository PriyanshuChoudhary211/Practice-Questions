class Solution {
public:
    bool compare(string &s,string &t)
    {
        if(s.length()-t.length()!=1)return false;
        int i=0,j=0;
        while(i<s.length() && j<t.length())
        {
            if(t[j]==s[i])
            {
                j++;i++;
            }
            else i++;
        }
        if(j!=t.length() &&i==s.length()) return false;
        else return true;
    }
   static bool comp(string &s1,string &s2)
    {
        return s1.length()<s2.length();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int maxi=1;
        vector<int>dp(words.size(),1);
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(compare(words[i],words[j]) && dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
        
    }
};