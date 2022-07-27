class Solution {
public:
    int func(int i,int k,vector<int>& arr,vector<int>&dp)
    {
      if(i==arr.size()) return 0;
      if(dp[i]!=-1)return dp[i];
        int n=arr.size();
        int len=0,maxi=INT_MIN,maxAns=INT_MIN;
      for(int ind=i;ind<min(n,i+k);ind++)
      {
          len++;
          maxi=max(maxi,arr[ind]);
          int ans= (maxi*len)+func(ind+1,k,arr,dp);
          maxAns=max(ans,maxAns);
      }
        return dp[i]=maxAns;
    }        
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size(),-1);
        return func(0,k,arr,dp);
    }
};