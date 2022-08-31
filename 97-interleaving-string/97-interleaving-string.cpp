class Solution {
public:
    bool func(string &s1,string &s2,string &s3,int i,int j,int k,vector<vector<int>>&dp)
    {
        if(i==s1.length() && j==s2.length() && k==s3.length()) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        bool x=false,y=false, z=false;
        if(s1[i]==s3[k] && s2[j]==s3[k])
            x=func(s1,s2,s3,i+1,j,k+1,dp) | func(s1,s2,s3,i,j+1,k+1,dp);
        else if(s1[i]==s3[k])
            y=func(s1,s2,s3,i+1,j,k+1,dp);
        else if(s2[j]==s3[k])
            z=func(s1,s2,s3,i,j+1,k+1,dp);
         else 
             return false;
         
        return dp[i][j] = x|y|z;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.length(),n2=s2.length(),n3=s3.length();
        if((n1+n2)!=n3) return false;
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        return func(s1,s2,s3,0,0,0,dp);
    }
};