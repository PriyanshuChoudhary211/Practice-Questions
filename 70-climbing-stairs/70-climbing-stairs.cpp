class Solution {
public:
    int climb(int n,vector<int>&dp)
    {
        if(n==0) return 1;
        else if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int x = climb(n-1,dp);
        int y = climb(n-2,dp);
        return dp[n]=x+y;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return climb(n,dp);
    }
};