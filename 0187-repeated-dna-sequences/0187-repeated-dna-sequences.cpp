class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int>m;
        vector<string>v;
         if(s.length()<10)
             return v;
         
        for(int i = 0 ; i<=s.length()-10;i++)
        {
            string sub = s.substr(i,10);
            m[sub]++;
        }
        for(auto it:m)
        {
            if(it.second >= 2)
            {
                v.push_back(it.first);
            }
        }
        return v;
        
        
    }
};