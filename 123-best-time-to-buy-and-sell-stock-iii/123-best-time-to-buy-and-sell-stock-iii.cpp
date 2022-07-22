class Solution {
public:
    int func(vector<int>&prices, int ind, int b, int cap,vector<vector<vector<int>>>&dp)
    {
       if(cap==0) return 0;
       if(ind==prices.size()) return 0;
        if(dp[ind][b][cap]!=-1) return dp[ind][b][cap];
        int pr=0;
       if(b)
       {
           pr=max(-prices[ind]+ func(prices,ind+1,0,cap,dp),func(prices,ind+1,1,cap,dp));
       }
        else
        {
            pr=max(prices[ind]+func(prices,ind+1,1,cap-1,dp),func(prices,ind+1,0,cap,dp));
        }
        return dp[ind][b][cap]=pr;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,0)));
                int pr=0;
        for(int ind=prices.size()-1;ind>=0;ind--)
        {
            for(int b = 1;b>=0;b--)
            {
                for(int cap=2;cap>=1;cap--)
                {
                    if(b)
                   {
                       pr=max(-prices[ind]+ dp[ind+1][0][cap],dp[ind+1][1][cap]);
                   }
                    else
                    {
                        pr=max(prices[ind]+dp[ind+1][1][cap-1],dp[ind+1][0][cap]);
                    }
                 dp[ind][b][cap]=pr; 
                }
            }
        }
            
        return dp[0][1][2];                              
    }
};