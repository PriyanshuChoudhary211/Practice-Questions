class compare
{
    public:
    bool operator()(pair<int,int>a, pair<int,int>b)
    {
        return a.first>b.first;
    }
};
class compare1
{
    public:
    bool operator()(pair<int,int>a, pair<int,int>b)
    {
        return a.second>b.second;
    }
};
class Solution {
public:
    
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare>p;
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare1>p1;

        vector<int>ans;
        for(int i = 0 ; i<nums.size();i++)
        {
            p.push(make_pair(nums[i],i));
        }
        while(p.size()>k)
        {
            p.pop();            
        }
        while(!p.empty())
        {
            p1.push(p.top());
            p.pop();
        }
        while(!p1.empty())
        {
            ans.push_back(p1.top().first);
            p1.pop();
        }
        return ans;
        
    }
};