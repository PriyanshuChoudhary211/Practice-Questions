int dp[101][27][101][101];
class Solution {
public:
    
    int func(string &s,int k, int prev,int l,int i)
    {
        if(k<0) return INT_MAX;
        if(i>=s.length()) return 0;
        if(dp[k][prev][l][i]!=-1) return dp[k][prev][l][i];
        int del=func(s,k-1,prev,l,i+1);
        int keep=0;
        if(prev==s[i]-'a')
        {
            if(l==1 || l==9 || l==99)
            {
                keep+=1;
            }
            keep =keep+func(s,k,s[i]-'a',l+1,i+1);
        }
        else
        {
            keep = 1+func(s,k,s[i]-'a',1,i+1);
        }
        return dp[k][prev][l][i]=min(keep,del);
    }
    int getLengthOfOptimalCompression(string s, int k) {
        
        memset(dp,-1,sizeof(dp));
        return func(s,k,26,0,0);
    }
};