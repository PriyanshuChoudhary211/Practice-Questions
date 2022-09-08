class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size()-1;
        int mid;
        int ans=-1;
        while(l<=h)
        {
             mid = l + (h-l)/2;
            if(nums[mid]==target)
            {  
                ans = mid;
                break;
            }            
            else if(nums[mid]>target)
                h = mid-1;
            else 
                l = mid+1;
        }
        if(ans==-1)
        {
            if(target>nums[nums.size()-1])
                return nums.size();
            else return l;
            
        }
        return ans;
        
    }
};