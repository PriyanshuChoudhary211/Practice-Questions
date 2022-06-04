class Solution {
public:
    // int func(vector<int>&nums,int ind,vector<int>&dp)
    // {
    //     if(ind==0) return nums[ind];
    //     if(ind<0) return 0;
    //     if(dp[ind]!=-1)return dp[ind];
    //     int pick = nums[ind] + func(nums,ind-2,dp);
    //     int notPick = 0 + func(nums,ind-1,dp);
    //     dp[ind] = max(pick,notPick);
    //     return dp[ind];        
    // }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size());
        dp[0] = nums[0];
        for(int i = 1; i<nums.size();i++)
        {
            int take = nums[i];
            if(i>1) take+=dp[i-2];
            int nottake = 0 + dp[i-1];
            dp[i] = max(take,nottake);
        }
        return dp[dp.size()-1];       
        
    }
};