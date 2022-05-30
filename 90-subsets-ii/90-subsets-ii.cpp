class Solution {
public:
    void fun(vector<int>&nums,int i, set<vector<int>>&s,vector<int>temp)
    {
        if(i>=nums.size())
        {
            s.insert(temp);
            return;
        }
        temp.push_back(nums[i]);
        fun(nums,i+1,s,temp);
        temp.pop_back();
        fun(nums,i+1,s,temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
          set<vector<int>>s;
        sort(nums.begin(),nums.end());
        vector<vector<int>>v;
        vector<int>temp;
        fun(nums,0,s,temp);
        for(auto it : s)
        {
            v.push_back(it);
        }
        return v;    
    }
};