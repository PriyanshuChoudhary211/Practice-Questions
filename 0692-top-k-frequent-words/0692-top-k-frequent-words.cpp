  class compare
    {
      public:
        bool operator()(pair<int,string>a,pair<int,string>b)
        {
            if(a.first<b.first)
            {
                return true;
            }
            else if(a.first == b.first)
            {
                return a.second>b.second;
            }
            return false;
        }
    };
class Solution {
public:
  
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>mp;
        vector<string>v;
        for(auto it :words)
        {
            mp[it]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,compare>q;
        for(auto it: mp)
        {
            q.push(make_pair(it.second,it.first));
        }
        while(!q.empty() && k--)
        {
            v.push_back(q.top().second);
            q.pop();
        }
        return v;
    }
};