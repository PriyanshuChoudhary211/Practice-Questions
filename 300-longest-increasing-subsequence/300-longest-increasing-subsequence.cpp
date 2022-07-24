
//MEMOIZATION BY DECLARING THE SIZE OF DP

// class Solution {
// public:
//     int func(vector<int>&nums,int ind,int last,vector<vector<int>>&dp)
//     {
//         if(ind==nums.size())return 0;
//         if(dp[ind][last+10001]!=-1) return dp[ind][last+10001];
        
//         int np=func(nums,ind+1,last,dp);
//         int p=0;
//         if(nums[ind]>last)
//         {
//             p=1+func(nums,ind+1,nums[ind],dp);
//         }
//         return dp[ind][last+10001]=max(p,np);
//     }
//     int lengthOfLIS(vector<int>& nums) {
        
//     vector<vector<int>>dp(nums.size(),vector<int>(20002,-1));
//      return func(nums,0,-10001,dp);   
//     }
// };
//

//MEMOIZATION WITHOUT DECLARING THE SIZE

// class Solution {
// public:
//     int find(vector<int>& nums,int ind,int last,vector<vector<int>> &dp){
//         if(ind==nums.size())return 0;
//         if(dp[ind][last+1]!=-1)return dp[ind][last+1];
//         int pick=INT_MIN,n_pick=INT_MIN;
        
//         n_pick=find(nums,ind+1,last,dp);
//         if(last==-1 || nums[ind]>nums[last]){
//             pick=1+find(nums,ind+1,ind,dp);
//         }
//         return dp[ind][last+1]=max(pick,n_pick);
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<vector<int>>dp(n,vector<int>(n+1,-1));
//         int x = find(nums,0,-1,dp);
//         for(int i=0;i<nums.size();i++)
//         {
//             for(int j=0;j<n+1;j++)
//                 cout<<dp[i][j]<<" ";
//             cout<<endl;
//         }
//         return x;
//     }
// };

//USING BINARY SEARCH 

class Solution {
public:
     int lengthOfLIS(vector<int>& nums) {
         vector<int>ans;
         ans.push_back(nums[0]);
         for(int i=0;i<nums.size();i++)
         {
             if(nums[i]>ans.back())
                 ans.push_back(nums[i]);
             else
             {
                 int x=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                 ans[x]=nums[i];
             }
         }
         return ans.size();
     }
};