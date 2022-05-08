/*
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>s;
        vector<vector<int>>ans;

        sort(nums.begin(),nums.end());
        do
        {
            s.insert(nums);
        }while(next_permutation(nums.begin(),nums.end()));
        for(auto it:s)
        {
            ans.push_back(it);
        }
        return ans;
    }
};
*/