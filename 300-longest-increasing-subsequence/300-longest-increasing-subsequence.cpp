class Solution {
public:
    int func(vector<int>&nums,int ind,int last,vector<vector<int>>&dp)
    {
        if(ind==nums.size())return 0;
        if(dp[ind][last+10001]!=-1) return dp[ind][last+10001];
        
        int np=func(nums,ind+1,last,dp);
        int p=0;
        if(nums[ind]>last)
        {
            p=1+func(nums,ind+1,nums[ind],dp);
        }
        return dp[ind][last+10001]=max(p,np);
    }
    int lengthOfLIS(vector<int>& nums) {
        
    vector<vector<int>>dp(nums.size(),vector<int>(20002,-1));
     return func(nums,0,-10001,dp);   
    }
};