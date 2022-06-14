class Solution {
public:
    int f(vector<int>&coins,int amount,int ind,vector<vector<int>> &dp)
    {
        if(ind == 0)
        {
            if(amount%coins[0]==0)
                return amount/coins[0];
            return 1e9;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int np=0+f(coins,amount,ind-1,dp);
        int p=INT_MAX;
        if(amount>=coins[ind])
        {
            p = 1 + f(coins,amount-coins[ind],ind,dp);
        }
        return dp[ind][amount]=min(p,np);
    }
    int coinChange(vector<int>& coins, int amount) {
        
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
       int x= f(coins,amount,coins.size()-1,dp);
        if(x == 1e9)
            return -1;
        return x;
    }
};