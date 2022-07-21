class Solution {
public:
    int func(vector<int>&prices,int ind,int buy,vector<vector<int>>&dp)
    {
        if(ind==prices.size()) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int prof=0;
        if(buy)
            prof=max(-prices[ind]+func(prices,ind+1,0,dp),func(prices,ind+1,1,dp));
        else
            prof=max(prices[ind]+func(prices,ind+1,1,dp),func(prices,ind+1,0,dp));
        return dp[ind][buy]=prof;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return func(prices,0,1,dp);
    }
};