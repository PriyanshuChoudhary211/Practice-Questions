class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),INT_MAX));
        for(int i = 0 ; i<matrix[0].size();i++)
        {
            dp[0][i] = matrix[0][i];
        }
        int x=INT_MAX,y=INT_MAX,z=INT_MAX;
        for(int i = 1; i<matrix.size();i++)
        {
            for(int j = 0 ; j<matrix[0].size();j++)
            {
                if(j==0)
                {
                    x = matrix[i][j]+dp[i-1][j];
                    y = matrix[i][j]+dp[i-1][j+1];
                    dp[i][j] = min(x,y);
                }
                else if(j==matrix[0].size()-1)
                {
                    x = matrix[i][j]+dp[i-1][j];
                    y = matrix[i][j]+dp[i-1][j-1];
                    dp[i][j] = min(x,y);
                }
                else
                {
                    x = matrix[i][j]+dp[i-1][j];
                    y = matrix[i][j]+dp[i-1][j-1];
                    z = matrix[i][j]+dp[i-1][j+1]; 
                    dp[i][j] = min(x,min(y,z));
                }
            }
        }
        int i=matrix.size()-1,ans = INT_MAX;
        for(int j = 0 ; j<matrix[0].size();j++)
        {
            if(dp[i][j]<ans)
                ans=dp[i][j];
        }
        return ans;
    }
};