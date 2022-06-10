class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>mp,mp2;
        for(auto i:s) mp[i]++;
        for(auto i:t) mp2[i]++;
        int count=0;
        for(auto i:mp)
        {
            if(i.second > mp2[i.first])
            {
                count += i.second - mp2[i.first];
            }
            
        }
        return count;
    }
};