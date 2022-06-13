class Solution {
public:
    bool isMatching(string word,string pattern)
    {
        map<char,char>mp;
        set<char>st;
        for(int i = 0 ; i<word.length();i++)
        {
            char w = word[i];
            char p = pattern[i];
            if(mp.find(p)!=mp.end())
            {
                if(w!=mp[p])
                    return false;
                    
            }
            else
            {
               if(st.find(w) != st.end()) return false;
                mp[p]=w;
                st.insert(w);
            }
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string>ans;
        for(int i = 0 ; i<words.size();i++)
        {
            if(isMatching(words[i],pattern) == true)
            {
                ans.push_back(words[i]);
            }
        
        }
        return ans;
    }
};