class Solution {
public:
    string toLowerCase(string s) {
        // string a="";
        for(int i = 0; i<s.length();i++)
        {
            if(s[i] >= 'A' && s[i]<='Z')
                s[i]+=32;
        }
        return s;
    }
};