class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char>a,b;
        for(int i = 0 ; i<s.length();i++)
        {
            if(a.size()>0 && s[i]=='#')  a.pop_back();
            else if(s[i]!='#')      a.push_back(s[i]);
        }
         for(int i = 0 ; i<t.length();i++)
        {
            if(b.size()>0 && t[i]=='#')  b.pop_back();
            else if(t[i]!='#')          b.push_back(t[i]);
        }
        if(a == b)
            return true;
        return false;
    }
};