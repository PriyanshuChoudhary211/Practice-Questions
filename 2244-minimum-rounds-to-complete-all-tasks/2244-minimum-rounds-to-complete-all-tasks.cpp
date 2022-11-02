class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int>mp;
        for(int i=0;i<tasks.size();i++)
        {
            mp[tasks[i]]++;
        }
        for(auto it:mp)
        {
            if(it.second==1) return -1;
        }
        int ans=0;
        for(auto it:mp)
        {
            int x=it.second;
            ans+=(x+2)/3;
        }
        return ans;
    }
};