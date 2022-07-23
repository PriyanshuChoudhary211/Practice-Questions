class Solution {
public:
    int func(vector<int>&prices,int ind, int b, vector<vector<int>>&dp)
    {
        if(ind>=prices.size()) return 0;
        if(dp[ind][b]!=-1) return dp[ind][b];
        int prof=0;
        if(b)
        {
            prof=max(-prices[ind]+func(prices,ind+1,0,dp),func(prices,ind+1,1,dp));
        }
        else
        {
            prof=max(prices[ind]+func(prices,ind+2,1,dp),func(prices,ind+1,0,dp));
        }
        return dp[ind][b]=prof;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+2,vector<int>(2,0));
         int prof=0;
        for(int ind=prices.size()-1;ind>=0;ind--)
        {
            for(int b=1;b>=0;b--)
            {
                 if(b)
                {
                    prof=max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
                }
                else
                {
                    prof=max(prices[ind]+dp[ind+2][1],dp[ind+1][0]);
                }
                dp[ind][b]=prof;
                
            }
        }        
        return dp[0][1];
    }
};