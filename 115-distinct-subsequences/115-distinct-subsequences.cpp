class Solution {
public:
    int func(string &s,string &t,int i,int j, vector<vector<int>>&dp)
    {
        if(j==t.length())
        {
            return 1;
        }
        else if(i==s.length()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int x=0,y=0,z=0;
        if(s[i]==t[j]) x=func(s,t,i+1,j+1,dp);
            y=func(s,t,i+1,j,dp);
        return dp[i][j]=x+y;
    }
    int numDistinct(string s, string t) {
        int n=s.length(),m=t.length();
        vector<vector<int>>dp(n+1,vector<int>(m,-1));
        return func(s,t,0,0,dp);
    }
};