class Solution {
public:
    int func(vector<vector<int>>& t,int i,int j,vector<vector<int>>& dp)
    {
        if(i==t.size()-1)
        {
            return t[i][j];
        }
        if(i>t.size()-1 || j>i)
        {
            return 40000000;
        }
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        int m = t[i][j] + func(t,i+1,j,dp);
        int n = t[i][j] + func(t,i+1,j+1,dp);
        
        return dp[i][j] = min(m,n);
    }
    int minimumTotal(vector<vector<int>>& t) {
        vector<vector<int>>dp(t.size(),vector<int>(t.size(),INT_MAX));
        return func(t,0,0,dp);
    }
};