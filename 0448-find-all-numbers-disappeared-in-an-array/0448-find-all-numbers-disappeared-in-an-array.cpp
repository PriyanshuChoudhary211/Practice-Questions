class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>res;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            int index=(nums[i]%n-1)%n;
            if(index<0)
                index+=n;
            nums[index]+=n;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=1 && nums[i]<=n)
                res.push_back(i+1);
        }
        return res;
    }
};