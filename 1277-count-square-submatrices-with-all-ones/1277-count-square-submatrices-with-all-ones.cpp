class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),0));
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++) dp[i][0]=matrix[i][0];
        for(int i=0;i<m;i++) dp[0][i]=matrix[0][i];
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j]==1)
                {
                    dp[i][j]=1+min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1]);
                }
                else dp[i][j]=0;
            }
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               sum+=dp[i][j];
            }
        }
        return sum;
    }
};