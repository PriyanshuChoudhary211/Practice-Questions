class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<int>s;
        for(int i = 0;i<allowed.length();i++)
        {
            s.insert(allowed[i]);
        }
        int count=0,f=0;
        for(int i =0;i<words.size();i++)
        {
            f=0;
            for(int j=0;j<words[i].length();j++)
            {
                if(s.find(words[i][j])==s.end())
                {
                    f = 1;
                    break;
                }
               
            }
            
            if(f==0) count++;
        }
        return count;
    }
};