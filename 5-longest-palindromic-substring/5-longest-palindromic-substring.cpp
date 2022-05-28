class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        
        for(int i = 0; i<n;i++)
        {
            for(int j = 0 ; j<n;j++)
            {
                if(i==j)
                    dp[i][j]=1;
            }
        }
        string ans="";
        ans+=s[0];
        int max = 1;
        
        for(int i = n-1; i>=0;i--)
        {
            for(int j = i+1 ; j<n;j++)
            {
                if(j-i==1)
                {
                    if(s[i]==s[j])
                    {
                        dp[i][j]=1;
                        
                    }
                     
                    
                }
                else
                {
                    if(s[i]==s[j] && dp[i+1][j-1]==1)
                    {
                        dp[i][j]=1;
                    }
                    
                }
                if(dp[i][j]==1 && j-i+1>max)
                {
                  string x = s.substr(i,j-i+1);
                  ans = x;
                  max = j-i+1;
                }
            }
        }
        return ans;
    }
};