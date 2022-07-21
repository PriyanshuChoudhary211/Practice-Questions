class Solution {
public:
    int func(string &s,string &t,int i,int j, vector<vector<int>>&dp)
    {
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        int x=0,y=0,m=0,n=0;
        if(s[i]==t[j])
            x=func(s,t,i-1,j-1,dp);
        else
        {
            y=1+func(s,t,i-1,j,dp);
            m=1+func(s,t,i,j-1,dp);
            n=1+func(s,t,i-1,j-1,dp);
        }
        return dp[i][j]=x+min(min(y,m),n);
        
    }
    int minDistance(string word1, string word2) {
        int n=word1.length(),m=word2.length();
         vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return func(word1,word2,n-1,m-1,dp);
    }
};