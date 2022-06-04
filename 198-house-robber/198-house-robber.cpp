class Solution {
public:
    int func(vector<int>&nums,int ind,vector<int>&dp)
    {
        if(ind==0) return nums[ind];
        if(ind<0) return 0;
        if(dp[ind]!=-1)return dp[ind];
        int pick = nums[ind] + func(nums,ind-2,dp);
        int notPick = 0 + func(nums,ind-1,dp);
        dp[ind] = max(pick,notPick);
        return dp[ind];        
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return func(nums,nums.size()-1,dp);
        
        
    }
};