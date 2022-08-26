class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        int c=0;
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
            c++;
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(j-i==1 && s[j]==s[i])
                {
                    dp[i][j]=1;
                    c++;
                }
                else
                {
                    if(s[i]==s[j] && dp[i+1][j-1]==1)
                    {
                        dp[i][j]=1;
                        c++;
                    }
                }
            }
        }
        return c;
    }
};