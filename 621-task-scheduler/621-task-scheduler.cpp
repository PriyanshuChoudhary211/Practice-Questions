class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0)
            return tasks.size();
        map<char,int>mp;
        for(auto it:tasks)
        {
            mp[it]++;
        }
        priority_queue<pair<int,char>>q,temp;
        for(auto it: mp)
        {
            q.push(make_pair(it.second,it.first));
        }
        int k = n+1;
        int ans = 0;
        while(!q.empty())
        {
            for(int i = 0 ; i<k;i++)
            {
                if(!q.empty())
                {
                    pair<int,char>x = q.top();
                    ans++;
                    x.first--;
                    if(x.first != 0)
                        temp.push(x);
                    q.pop();
                }
                else
                {
                    if(temp.empty())
                        return ans;
                    ans++;
                }
            }
            while(!temp.empty())
            {
                q.push(temp.top());
                temp.pop();
            }
        }
        return ans;
    }
};