class Solution {
public:
    int func(vector<vector<int>>& grid,vector<vector<int>>& dp,int i,int j)
    {
       if(i == 0 && j == 0) return grid[i][j];
       if(i<0 || j<0) return 4000000;
       if(dp[i][j]!=-1) return dp[i][j];
        int mini = grid[i][j] + func(grid,dp,i-1,j);
        int mini2 = grid[i][j] + func(grid,dp,i,j-1);
        return dp[i][j] = min(mini, mini2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return func(grid,dp,n-1,m-1);    
    }
};