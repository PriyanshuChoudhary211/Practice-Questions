class Solution {
public:
    int func(int amount,vector<int>&coins,int ind,vector<vector<int>>&dp)
    {
        if(amount==0)return 1;
        else if(amount<0)return 0;
        if(ind==coins.size()-1)
        {
            if(amount%coins[ind]==0) return 1;
            else return 0;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int np = func(amount,coins,ind+1,dp);
        int p=0;
        if(amount-coins[ind]>=0)
        {
            p = func(amount-coins[ind],coins,ind,dp);
        }
        return dp[ind][amount]=np+p;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return func(amount,coins,0,dp);
    }
};