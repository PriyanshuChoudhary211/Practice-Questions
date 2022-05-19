class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int>mp;
        for(int i = 0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int k = 0;
        for(auto it:mp)
        {
            if(it.second>=2)
            {
                nums[k] = nums[k+1] = it.first;
                k+=2;
            }
            else
                nums[k++] = it.first;
        }
        return k;
    }
};