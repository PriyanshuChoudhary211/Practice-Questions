class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int sum2=sum;
        vector<int>n(nums.size());
        vector<int>m(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            n[i]=sum-nums[i];
            sum-=nums[i];
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            m[i]=sum2-nums[i];
            sum2-=nums[i];
        }
        for(int i=0;i<nums.size();i++)
        {
            if(n[i]==m[i])
                return i;
        }
        return -1;
        
    }
};