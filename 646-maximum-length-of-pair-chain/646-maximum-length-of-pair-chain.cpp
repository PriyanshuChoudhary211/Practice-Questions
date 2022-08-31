class Solution {
public:
    int func(vector<vector<int>>& pairs,int n,int i,int last,vector<vector<int>>&dp)
    { 
        if(i==n) return 0;
        if(dp[i][last+1]!=-1) return dp[i][last+1];
        int np=func(pairs,n,i+1,last,dp);
        int p=0;
        if(last==-1||pairs[i][0]>pairs[last][1])
            p=1+func(pairs,n,i+1,i,dp);
        
        return dp[i][last+1]=max(p,np);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
       int n=pairs.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        sort(pairs.begin(),pairs.end());
       return func(pairs,n,0,-1,dp);
    }
};