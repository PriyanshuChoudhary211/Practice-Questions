class Solution {
public:
    int func(string &s1,string &s2,int n1,int n2, vector<vector<int>>&dp)
    {
        if(n1<0||n2<0)
            return 0;
        if(dp[n1][n2]!=-1) return dp[n1][n2];
        int x=0,y=0,c=0;
        if(s1[n1]==s2[n2])  c = 1+func(s1,s2,n1-1,n2-1,dp);
        else
        {
            x = func(s1,s2,n1-1,n2,dp);
            y=func(s1,s2,n1,n2-1,dp);
        }
        return dp[n1][n2]=c+max(x,y);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.length()-1,n2=text2.length()-1;
         vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        return func(text1,text2,n1,n2,dp);
    }
};