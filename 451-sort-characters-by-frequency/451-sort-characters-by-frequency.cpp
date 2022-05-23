class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mp;
        for(auto it:s)
        {
            mp[it]++;
        }
        priority_queue<pair<int,int>>q;
        for(auto it:mp)
        {
            q.push(make_pair(it.second,it.first));
        }
        string x = "";
        while(!q.empty())
        {
            int m = q.top().first;
            while(m--)
               x+=q.top().second;
            q.pop();
        }
        return x;
    }
};