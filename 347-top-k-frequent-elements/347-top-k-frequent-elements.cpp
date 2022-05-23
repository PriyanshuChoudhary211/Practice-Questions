class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         map<int,int>mp;
        for(auto it:nums)
        {
            mp[it]++;
        }
        priority_queue<pair<int,int>>q;
        for(auto it:mp)
        {
            q.push(make_pair(it.second,it.first));
        }
        vector<int>ans;
        while(k--)
        {
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    
    }
};