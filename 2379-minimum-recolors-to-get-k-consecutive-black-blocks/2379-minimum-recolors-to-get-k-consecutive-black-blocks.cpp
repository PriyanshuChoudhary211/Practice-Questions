class Solution {
public:
    int func(string &s,int n, int k, int i, int c,vector<vector<int>>&dp)
    {
        if(c>=k) return 0;
        if(i>=n) 
            return 1e9;
        
        if(dp[i][c]!=-1) return dp[i][c];
        int x=1e9,y=1e9,z=1e9;
         if(s[i]=='B')
             x=func(s,n,k,i+1,c+1,dp);
        else
        {
            y=func(s,n,k,i+1,0,dp);
             z=1+func(s,n,k,i+1,c+1,dp);
        }
        
        return dp[i][c]=min(x,min(y,z));
    }
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size();
        vector<vector<int>>dp(n,vector<int>(1000,-1));
        return func(blocks,n,k,0,0,dp);
    }
};