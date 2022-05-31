class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>>arr;
        vector<int>ans(2);
        for(int i = 0 ; i<nums.size();i++)
        {
            for(int j = 0 ; j<nums[i].size();j++)
            {
                arr.push_back({nums[i][j],i});
            }
        }
        int n = nums.size();
        sort(arr.begin(),arr.end());
        map<int,int>mp;
        int total=0;
        int range = INT_MAX;
        int i=0,j=0;
        while(j<arr.size())
        {
            mp[arr[j].second]++;
            if(mp[arr[j].second]==1)
                total+=1;
            while(total==n)
            {
                if(arr[j].first-arr[i].first < range)
                {
                    ans[0] = arr[i].first;
                    ans[1] = arr[j].first;
                    range = arr[j].first-arr[i].first;
                }
                mp[arr[i].second]--;
                if(mp[arr[i].second]==0)
                    total--;
                i++;
            }
            j++;
        }
        
        return ans;
    }
};