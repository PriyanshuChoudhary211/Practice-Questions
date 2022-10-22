class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length()>s.length())
            return "";
        
        if(s==t)
            return s;
        int i = 0, j = 0,start=0;
        int count=0,strSize = INT_MAX;
        map<char,int>mp;
        for(auto it: t)
        {
            mp[it]++;
        }
        int map_size = mp.size();
        while(j<s.length())
        {
            
            if(mp.find(s[j])!=mp.end())
            {
                mp[s[j]]--;
                if(mp[s[j]]>=0)
                {
                    count++;
                }
            }
            while(count==t.length())
            {   
              if(j-i+1 < strSize)
              {
                  start = i;
                  strSize = j-i+1;
              }
                if(mp.find(s[i])!=mp.end())
                {
                    mp[s[i]]++;
                     if(mp[s[i]]>0)
                       count--;
                }
               
                i++;
            }
            j++;
        }
        if(strSize == INT_MAX)
            strSize = 0;
        return s.substr(start,strSize);
    }
};