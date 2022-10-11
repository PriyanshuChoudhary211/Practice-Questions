class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3) return false;
        int a=nums[0],b=INT_MAX;
        for(int i=1;i<nums.size();i++)
        {
            if(b==INT_MAX && nums[i]>a) b=nums[i];
            else if(b==INT_MAX && nums[i]<a) a=nums[i];
            else if(b!=INT_MAX && nums[i]>b) return true;
            else if(nums[i]<b && nums[i]>a) b=nums[i];
            else if(nums[i]<b && nums[i]<a) a=nums[i];
        }
        return false;
    }
};