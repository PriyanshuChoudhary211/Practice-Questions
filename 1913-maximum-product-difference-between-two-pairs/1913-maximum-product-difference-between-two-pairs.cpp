class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int minprod = nums[0] * nums[1];
        int maxprod = nums[nums.size()-1] * nums[nums.size()-2];
        return maxprod - minprod;
    }
};