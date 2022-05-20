class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,e = nums.size()-1;
        while(l<=e)
        {
            int mid = l + (e-l)/2;
            if(l == e) return nums[l];
            if(nums[mid]>nums[e])
            {
                l = mid+1;
            }
            else if(nums[mid]<nums[e])
                e = mid;
            else 
                e--;
                
            
        }
        return -1;
        
    }
};