class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int i=0,j=0,n=nums.size();
        long long c=0;
        int min=nums[0],max=nums[0];
        for(int i = 0;i<n;i++)
        {
            min = nums[i];
            max = nums[i];
            for(int j = i+1;j<n;j++)
            {
                if(nums[j]<min)
                    min = nums[j];
                if(nums[j]>max)
                    max = nums[j];
                c+=max-min;
            }
        }
        return c;
    }
};