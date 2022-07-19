class Solution {
public:
    int robHouse(vector<int>&nums,vector<int>&dp,int n)
    {
        if(n==nums.size()-1)
            return nums[n];
        else if(n>nums.size()-1) return 0;
        if(dp[n]!=-1) return dp[n];
        int np = robHouse(nums,dp,n+1);
        int pick = nums[n] + robHouse(nums,dp,n+2);
        return dp[n]=max(np,pick);        
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return robHouse(nums,dp,0);
    }
};