class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>dp(n,1),hash(n,-1);
        int lastIndex=0,maxi=1;
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(nums[i]%nums[prev]==0 && 1+dp[prev]>dp[i])
                {
                    dp[i]= 1+dp[prev];
                    hash[i]=prev;
                }
            }
         if(dp[i]>maxi)
         {
              maxi=dp[i];
              lastIndex=i;
         }
                
        }
        vector<int>temp;
        temp.push_back(nums[lastIndex]);
        while(hash[lastIndex]!=-1)
        {
            lastIndex=hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }
        return temp;
    }
};