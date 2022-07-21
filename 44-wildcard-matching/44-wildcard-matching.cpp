class Solution {
public:
    bool func(string &s, string &t , int i,int j, vector<vector<int>>&dp)
    {
        if(i<0 && j<0) return 1;
        else if(j<0)return 0;
        else if(i<0)
        {
            for(int ii = j;ii>=0;ii--)
            {
                if(t[ii]!='*')
                    return 0;
            }
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int x=0,y=0;
        if(s[i]==t[j]||t[j]=='?') x=func(s,t,i-1,j-1,dp);
        else if(t[j]=='*')
        {
            y=func(s,t,i,j-1,dp)||func(s,t,i-1,j,dp);
        }
       return dp[i][j]=x||y;
    }
    bool isMatch(string s, string t) {
        int n=s.length(),m=t.length();
         vector<vector<int>>dp(n+1,vector<int>(m,-1));
        return func(s,t,n-1,m-1,dp);
    }
};