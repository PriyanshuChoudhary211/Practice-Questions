class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
                vector<int>ans;
        if(s.length()<p.length()) return ans;
        vector<int>x(26,0),c(26,0);
        for(int i=0;i<p.length();i++)
        {
            c[p[i]-'a']+=1;
        }
        int i=0;
        int j=0;
        while(j<p.length())
        {
            x[s[j]-'a']+=1;
            j++;
        }
        //
        while(j<s.length())
        {
            if(x==c)ans.push_back(i);
            x[s[i]-'a']-=1;
            i++;
            x[s[j]-'a']+=1;
            j++;
        }
        if(x==c) ans.push_back(i);
        return ans;
    }
    
};