class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
       int c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val)
                c++;
        }
                remove(nums.begin(),nums.end(),val);

        return nums.size()-c;
    }
};