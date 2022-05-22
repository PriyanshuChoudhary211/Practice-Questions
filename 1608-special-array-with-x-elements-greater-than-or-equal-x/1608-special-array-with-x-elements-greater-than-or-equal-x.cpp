class Solution {
public:
    int binarySearch(vector<int>&nums,int x)
    {
        int s = 0,e = nums.size()-1,res=-1;
        while(s<=e)
        {
            int mid = (s+e)/2;
            if(nums[mid]>=x)
            {
                e = mid-1;
                res = mid;
            }
            else if(nums[mid]<x)
                s = mid+1;
        }
        return res;     
    }
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int j = 0;
        for(int i = 0 ; i<=nums.size();i++)
        {
            int x = binarySearch(nums,i);
            if(i == nums.size()-x)
                return i;
        }
        return -1;
    }
};