class Solution {
public:
    int func(int e,int n,vector<vector<int>>&dp)
    {
        if(n==0||n==1||e==1) return n;
        if(dp[e][n]!=-1) return dp[e][n];
        int l=1,h=n;
        int mini=INT_MAX,x;
        while(l<=h)
        {
            int mid=(l+h)/2;
            int left=func(e-1,mid-1,dp);
            int right=func(e,n-mid,dp);
            
             x=1+max(left,right);
            
            if(left<right)
                l=mid+1;
            else h=mid-1;
            mini=min(mini,x);
        }
        return dp[e][n]=mini;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
        return func(k , n,dp);
    }
};