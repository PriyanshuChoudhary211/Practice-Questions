class Solution {
public:
    int func(string &s1,string &s2,int n1,int n2, vector<vector<int>>&dp)
    {
        if(n1<0||n2<0)
            return 0;
        if(dp[n1+1][n2+1]!=-1) return dp[n1+1][n2+1];
        int x=0,y=0,c=0;
        if(s1[n1]==s2[n2])  c = 1+func(s1,s2,n1-1,n2-1,dp);
        else
        {
            x = func(s1,s2,n1-1,n2,dp);
            y=func(s1,s2,n1,n2-1,dp);
        }
        return dp[n1+1][n2+1]=c+max(x,y);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.length()-1,n2=text2.length()-1;
         vector<vector<int>>dp(n1+2,vector<int>(n2+2,-1));
        int x= func(text1,text2,n1,n2,dp);
        string s="";
        int i=n1+1,j=n2+1;
        //FOR PRINTING THE LONGEST COMMON SUBSEQUENCE 
        // for(int i = 0;i<=n1+1;i++)
        // {
        //     for(int j=0;j<=n2+1;j++)
        //         cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        // while(i>0 && j>0)
        // {
        //     if(text1[i-1]==text2[j-1])
        //     {
        //         s = text1[i-1]+s;
        //         i--;
        //         j--;
        //     }
        //     else if(dp[i][j-1]>dp[i-1][j])
        //     {
        //         j=j-1;
        //     }
        //     else i=i-1;
        // }
        // cout<<s;
          return x;
    }
};