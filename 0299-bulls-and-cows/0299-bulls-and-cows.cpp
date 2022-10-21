class Solution {
public:
    string getHint(string s, string g) {
        int c_p=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==g[i])
                c_p++;
        }
        map<int,int>mp1;
        for(int i=0;i<s.length();i++)
        {
            mp1[s[i]]++;
          
        }
        int w_p=0;
        for(int i=0;i<g.length();i++)
        {
           if(mp1.find(g[i])!=mp1.end())
           {
               if(mp1[g[i]]>0)
               {   
                   mp1[g[i]]--;
                    w_p++;
               }
           }
        }
        string ans="";
        int a=w_p-c_p;
        ans+=to_string(c_p)+'A'+to_string(a)+'B';
        
        return ans;
    }
};