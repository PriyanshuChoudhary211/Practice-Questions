class Solution {
public:
    string reverseWords(string s) {
       string ans="",res="";
       
        for(int i = 0 ; i<s.length();i++)
        {
            if(s[i]==' ' )
            {  res+=ans;
               ans="";
               res+=' ';
               continue;
            }
            ans = s[i]+ans;
        }
        res += ans;
        return res;
    }
};