class Solution {
public:
    bool func(vector<int>& piles,int i,int j,vector<vector<int>>&dp,int sa,int sb,int turn)
    {
        if(i>j)
        {
            if(sa>sb) return 1;
            else return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        bool x,y;
        if(turn)
        {
            sa+=max(piles[i],piles[j]);
            x=func(piles,i+1,j,dp,sa,sb,0);
            y=func(piles,i,j-1,dp,sa,sb,0);
        }
        else
        {
            sb+=max(piles[i],piles[j]);
            x=func(piles,i+1,j,dp,sa,sb,1);
            y=func(piles,i,j-1,dp,sa,sb,1);
        }
        return dp[i][j]=x|y;
    }
    bool stoneGame(vector<int>& piles) {
      
        vector<vector<int>>dp(piles.size(),vector<int>(piles.size(),-1));
        int n=piles.size();
        return func(piles,0,n-1,dp,0,0,1);
    }
};