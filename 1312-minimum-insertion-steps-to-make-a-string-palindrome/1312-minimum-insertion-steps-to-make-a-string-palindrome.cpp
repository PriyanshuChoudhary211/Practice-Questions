class Solution {
public:
    int func(string &s1,string &s2,int i,int j, vector<vector<int>>&dp)
    {
        if(i<0 || j<0)return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int x=0,y=0,m=0;
        if(s1[i]==s2[j])
            x = 1+func(s1,s2,i-1,j-1,dp);
        else
        {
            y=func(s1,s2,i-1,j,dp);
            m=func(s1,s2,i,j-1,dp);
        }
        return dp[i][j]=x+max(y,m);
    }
    int minInsertions(string s) {
        string s2=s;
        int n = s.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        reverse(s.begin(),s.end());
        
        int m = func(s,s2,n-1,n-1,dp);
        return n-m;
    }
};