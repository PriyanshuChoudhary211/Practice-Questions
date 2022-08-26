class Solution {
public:
    int func(int x,vector<int>&dp)
    {
        if(x==1) return 0;
        if(dp[x]!=-1)return dp[x];
        int y1=0,y2=0;
        if(x%2==0) 
             y1=1+func(x/2,dp);
        else
             y2=1+func(3*x+1,dp);
        return dp[x]=y1+y2;
    }
    int getKth(int lo, int hi, int k) {
        int n=hi-lo+1;
        vector<int>dp(1e6,-1);
        vector<vector<int>>sorted(n,vector<int>(2));
        for(int i=0;i<n;i++)
        {
            sorted[i][1]=lo+i;
        }
        for(int i=0;i<n;i++)
        {
            sorted[i][0]=func(lo+i,dp);
        }
        sort(sorted.begin(),sorted.end());
        return sorted[k-1][1];
    }
};