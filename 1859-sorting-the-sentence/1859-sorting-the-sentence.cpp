class Solution {
public:
    string sortSentence(string s) {
        vector<pair<int,string>>ans;
        int i=0, x;
      while(i<s.length())
      {
          string str="";
            while(s[i] != '\0' && s[i]!=' ')
            {
                if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' &&s[i]<='z'))
                   {
                      str+=s[i];
                       
                   }
                else
                   x = s[i]-'0';
                   i++;
            }
            ans.push_back({x,str});
                   i++;
       } 
      string res="";
      sort(ans.begin(),ans.end());
      for(auto i:ans)
      {
        res+=i.second;
          res+=" ";
      }
      res.pop_back();
    return res;
    }
};