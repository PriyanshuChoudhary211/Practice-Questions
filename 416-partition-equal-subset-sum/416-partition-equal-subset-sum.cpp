class Solution {
public:
    bool f(vector<int>&nums,int i,int st,int sum,vector<int>&dp)
    {
        if(i<0) return st==(sum/2);
        if(dp[st] != -1) return dp[st];
        bool t = f(nums,i-1,st+nums[i],sum,dp);
        bool nt = f(nums,i-1,st,sum,dp);
        
        return dp[st] = t||nt;
    }
    bool canPartition(vector<int>& nums) {
        int x = accumulate(nums.begin(),nums.end(),0);
        if(x%2 != 0) return false;
        vector<int>dp(x,-1);
        return f(nums,nums.size()-1,0,x,dp);
    }
};