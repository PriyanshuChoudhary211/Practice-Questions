class Solution {
public:
     int func(vector<int>&nums,int ind,vector<int>&dp)
    {
        if(ind==0) return nums[ind];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        
       int pick = nums[ind] + func(nums,ind-2,dp);
        int notPick = 0 + func(nums,ind-1,dp);
       return dp[ind] = max(pick,notPick);       
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int x = nums[nums.size()-1];
        vector<int>dp1(nums.size(),-1);
        vector<int>dp2(nums.size(),-1);
        nums.pop_back();
        
        int ans1 = func(nums,nums.size()-1,dp1);
        nums.push_back(x);
        auto it = nums.begin();
        nums.erase(it);
        
        int ans2 = func(nums,nums.size()-1,dp2);
        return max(ans1,ans2);
    }
};