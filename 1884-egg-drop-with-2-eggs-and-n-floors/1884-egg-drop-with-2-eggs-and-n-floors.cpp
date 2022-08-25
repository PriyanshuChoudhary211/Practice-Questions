class Solution {
public:
    int func(int e, int n,vector<vector<int>>&dp)
    {
        if(n==0||n==1) return n;
        if(e==1) return n;
        if(dp[e][n]!=-1) return dp[e][n];
        int mini=INT_MAX;
        for(int i=1;i<=n;i++)
        {
            mini=min(mini,1+max(func(e-1,i-1,dp),func(e,n-i,dp)));
        }
        return dp[e][n]=mini;
    }
    int twoEggDrop(int n) {
        vector<vector<int>>dp(3,vector<int>(n+1,-1));
         return func(2,n,dp);
    }
};