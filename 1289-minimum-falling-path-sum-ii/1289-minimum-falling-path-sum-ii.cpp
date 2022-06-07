class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        for(int i = 0 ; i<m;i++)
        {
            dp[0][i] = grid[0][i];
        }
        int ans = INT_MAX;
        for(int i = 1; i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                ans = INT_MAX;
                for(int k = 0 ; k<m;k++)
                {
                    if(j!=k)
                    {
                        ans = min(ans,dp[i-1][k]);
                    }
                }
                dp[i][j] = ans+grid[i][j];
            }
        }
        int i = n-1;
        int res = INT_MAX;
        for(int j = 0; j<m;j++)
        {
            res = min(res,dp[i][j]);
        }
        return res;
    }
};