class Solution {
public:
    int func(vector<int>&piles,int M,int i,vector<vector<int>>&dp)
    {
        if(i>=piles.size())return 0;
        if(dp[i][M]!=-1) return dp[i][M];
        int ans=INT_MIN,tot=0;
        for(int j=0;j<2*M;j++)
        {
            if(i+j<piles.size())
                 tot+=piles[i+j];
            ans=max(ans,tot-func(piles,max(M,j+1),i+j+1,dp));
        }
        return dp[i][M]= ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(piles.size(),vector<int>(2*piles.size(),-1));

       int diff=func(piles,1,0,dp);
        int sum=accumulate(piles.begin(),piles.end(),0);
        
        return (sum+diff)/2;
        
    }
};