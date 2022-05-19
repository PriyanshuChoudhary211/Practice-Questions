class Solution {
public:
    int gap(vector<int>&nums, int x)
    {
        int f=-1,l,i=0;
        while(i<nums.size())
        {
            if(nums[i] == x)
            {
                if(f == -1)
                   f = i;
                l = i;
               
            }
             i++;
        }
        return l-f+1;
    }
    int findShortestSubArray(vector<int>& nums) {
        map<int,int>mp;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(auto it:nums)
        {
            mp[it]++;
        }
        for(auto it : mp)
        {
            if(maxi<it.second)
            {
                maxi = it.second;
            }
        }
        vector<int>v;
        for(auto it:mp)
        {
            if(it.second == maxi)
                v.push_back(it.first);
        }
        for(auto it:v)
        {
             mini = min(mini,gap(nums,it));
        }
        
        return mini;
    }
};