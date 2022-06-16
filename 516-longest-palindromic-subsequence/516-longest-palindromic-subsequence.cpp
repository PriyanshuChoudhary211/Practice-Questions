class Solution {
public:
    int f(string &s,string &s1,int i,int j,vector<vector<int>>&dp)
    {
        int c=0,x=0,y=0;
        if(i==s.length() || j == s.length())
            return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s1[j])
        {
            c = 1+f(s,s1,i+1,j+1,dp);
        }
        else
        {
            x = f(s,s1,i+1,j,dp);
            y = f(s,s1,i,j+1,dp);
        }
        return dp[i][j] = c+max(x,y);
            
    }
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s1.begin(),s1.end());
        vector<vector<int>>dp(s.length(),vector<int>(s1.length(),-1));
        return f(s,s1,0,0,dp);
    }
};