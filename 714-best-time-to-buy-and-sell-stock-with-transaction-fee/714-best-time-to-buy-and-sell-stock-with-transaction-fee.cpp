class Solution {
public:
     int func(vector<int>&prices,int ind, int b, vector<vector<int>>&dp,int fee)
    {
        if(ind==prices.size()) return 0;
        if(dp[ind][b]!=-1) return dp[ind][b];
        int prof=0;
        if(b)
        {
            prof=max(-prices[ind]+func(prices,ind+1,0,dp,fee),func(prices,ind+1,1,dp,fee));
        }
        else
        {
            prof=max(prices[ind]+func(prices,ind+1,1,dp,fee)-fee,func(prices,ind+1,0,dp,fee));
        }
        return dp[ind][b]=prof;
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return func(prices,0,1,dp,fee);
    }
};