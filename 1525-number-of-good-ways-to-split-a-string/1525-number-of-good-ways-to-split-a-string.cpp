class Solution {
public:
    int numSplits(string s) {
       map<char,int>mp1,mp2;
        int c=0;
       for(auto it:s)
           mp2[it]++;
        for(int i=0;i<s.length();i++)
        {
            mp1[s[i]]++;
            mp2[s[i]]--;
            if(mp2[s[i]]==0) mp2.erase(s[i]);
            if(mp1.size()==mp2.size())
                c++;
        }
        return c;
    }
};