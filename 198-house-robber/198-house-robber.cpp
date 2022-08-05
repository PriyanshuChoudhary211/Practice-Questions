class Solution {
public:
    int func(vector<int>&nums,int ind,vector<int>&dp)
    {
        if(ind>=nums.size())return 0; 
        if(dp[ind]!=-1)return dp[ind];
        int np=func(nums,ind+1,dp);
        int p=nums[ind]+func(nums,ind+2,dp);
        return dp[ind] = max(p,np);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return func(nums,0,dp);
    }
};