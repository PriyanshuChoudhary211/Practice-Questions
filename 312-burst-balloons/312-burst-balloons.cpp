class Solution {
public:
    int func(vector<int>&nums,int i,int j,vector<vector<int>>&dp){
        if(i>j) return 0;
       // if(i==j)return nums[i];
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int maxi=INT_MIN,steps;
        for(int ind=i;ind<=j;ind++){
            steps= ((i-1)<0?1:nums[i-1])*nums[ind]*((j+1)>=nums.size()?1:nums[j+1])+ func(nums,i,ind-1,dp) +func(nums,ind+1,j,dp);
            maxi=max(maxi,steps);
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        return func(nums,0,nums.size()-1,dp);
    }
};