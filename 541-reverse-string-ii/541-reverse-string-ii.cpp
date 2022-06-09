class Solution {
public:
    string reverseStr(string s, int k) {
        string ans="";
        string res="";
        int i = 0;
         while(i<s.length())
         {
             int x = k;
             while(i<s.length() && x--)
             {
                 ans = s[i]+ans;
                 i++;
             }
             res += ans;
             x = k;
             while(i<s.length() && x--)
             {
                 res+=s[i];
                 i++;
             }
             ans = "";
         }
        return res;
    }
};