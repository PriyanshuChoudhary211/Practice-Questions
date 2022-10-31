class Solution {
public:
    int dp[101];
    int func(string s,int i)
    {
        if(i==s.length()) return 1;
        if(i==s.length()-1)
        {
            if(s[i]<='9'&&s[i]>='1')
            {
                return 1;
            }
            return 0;
        }
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        int l=0,r=0;
        if(s[i]>='1' && s[i]<='9')
          l=func(s,i+1);
        string t="";
        t=t+s[i]+s[i+1];
        int tr=stoi(t);
        if(tr>=10 && tr<=26)
         r=func(s,i+2);
        return dp[i] = l+r;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return func(s,0);
    }
};