class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size()==2)
            return min(cost[0],cost[1]);
        int n=cost.size();
        vector<int> dp(n+1,0);
        for(int i=2;i<=n;i++)
        {
            dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        }
        return dp[n];
    }
};