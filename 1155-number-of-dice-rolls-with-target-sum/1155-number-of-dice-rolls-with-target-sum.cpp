#define mod 1000000007
class Solution {
public:
    int dp[31][10001];
    int func(int cd,int n,int k, int t)
    {
        if(cd>n)
        {
            if(t==0) return 1;
            return 0;
        }
        if(t<=0) return 0;
        if(dp[cd][t]!=-1) return dp[cd][t];
        int ans=0;
        for(int i=1;i<=k;i++)
        {
            ans=(ans+(func(cd+1,n,k,t-i)%mod))%mod;
        }
        return dp[cd][t]=ans%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        if(n==1)
        {
           if(k>=target) return 1;
        }
        if(n*k<target) return 0;
        return func(1,n,k,target);
    }
};