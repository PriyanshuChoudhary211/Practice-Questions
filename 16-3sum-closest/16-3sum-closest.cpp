class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
       int i = 0;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int diff = INT_MAX;
        int ans=0;
        int x,k;
      for(;i<n-2;i++)
            {
          if(i>0 && nums[i]==nums[i-1])continue;
                
                int j = i+1;
                k=n-1;
                x=target-nums[i];
               
                while(j<k)
                {
                 
                    if(nums[j]+nums[k] == x)
                    {
                        return target;                        
                    }
                    else if(nums[j]+nums[k]<x)
                    {
                        if(diff>abs(target-nums[i]-nums[j]-nums[k])){
                            diff=abs(target-nums[i]-nums[j]-nums[k]);
                            ans = nums[i]+nums[j]+nums[k];
                        }
                        j++;
                    }
                    else{
                         if(diff>abs(target-nums[i]-nums[j]-nums[k])){
                            diff=abs(target-nums[i]-nums[j]-nums[k]);
                            ans = nums[i]+nums[j]+nums[k];
                        }
                        k--;
                    }
                }
               
            }
      
        return ans;
    }
};