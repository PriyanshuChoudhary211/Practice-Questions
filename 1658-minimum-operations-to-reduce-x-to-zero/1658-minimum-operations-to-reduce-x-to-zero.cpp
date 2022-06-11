class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int ans=INT_MIN,sum=accumulate(nums.begin(),nums.end(),0);
        int c_sum=0;        
        int i = 0,j=0;
        int target = sum-x;
        while(j<nums.size())
        {
            c_sum += nums[j];
            while(i<=j && c_sum>target)
            {
                c_sum -= nums[i];
                i++;
            }
              if(c_sum == target)
            {
                ans = max(ans,j-i+1);
             
            }
            j++;
        }
        if(ans ==INT_MIN) return -1;
        return nums.size()-ans;
    }
};