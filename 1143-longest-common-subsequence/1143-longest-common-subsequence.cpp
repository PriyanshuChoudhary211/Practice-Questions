class Solution {
public:
    
    int f(string &t1,string &t2,int i,int j,vector<vector<int>>&dp)
    {
        int c=0,x=0,y=0;
        if(i==t1.length() || j==t2.length())
        {
          return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(t1[i]==t2[j]) {
           c=1+f(t1,t2,i+1,j+1,dp);
        }
        else
        {
           x = f(t1,t2,i+1,j,dp);
           y = f(t1,t2,i,j+1,dp);
        }
      return dp[i][j]=c+max(x,y);        
    }
    int longestCommonSubsequence(string t1, string t2) {
        vector<vector<int>>dp(t1.length(),vector<int>(t2.length(),-1));
        return f(t1,t2,0,0,dp);
    }
};