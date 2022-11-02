class Solution {
public:
    int func(int i,vector<int>&cost,vector<int>&dp)
    {
        if(i>=cost.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int c1=0,c2=0;
         c1=cost[i]+func(i+1,cost,dp);
         c2=cost[i]+func(i+2,cost,dp);
        
        return dp[i]=min(c1,c2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+1,-1);
        int a=func(0,cost,dp);
        int b=func(1,cost,dp);
        return min(a,b);
    }
};