class Solution {
public:
    int f(int i,int j1,int j2,vector<vector<vector<int>>>&dp,vector<vector<int>>& a)
    {
        if(j1<0 || j1>=a[0].size() || j2<0 || j2>=a[0].size()) return -1e8;
        if(i==a.size()-1)
        {
            if(j1==j2) return a[i][j1] ;
            return a[i][j1]+a[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int maxi = 0;
        for(int x = -1; x<=1;x++)
        {
            for(int y = -1; y<=1;y++)
            {
                if(j1 == j2) maxi = max(a[i][j1]+f(i+1,j1+x,j2+y,dp,a),maxi);
                else maxi = max(a[i][j2]+a[i][j1]+f(i+1,j1+x,j2+y,dp,a),maxi);
            }
        }
        return dp[i][j1][j2] = maxi;   
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int i = grid.size();
        int j = grid[0].size();
        vector<vector<vector<int>>>dp(i,vector<vector<int>>(j,vector<int>(j,-1)));
        return f(0,0,j-1,dp,grid);
    }
};