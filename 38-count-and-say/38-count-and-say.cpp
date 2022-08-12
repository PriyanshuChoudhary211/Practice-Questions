class Solution {
public:
    string countAndSay(int n) {
       int counter = 0; 
        if(n==1)
            return "1";

             string s=countAndSay(n-1);
             string res = "";
             for(int i=0;i<s.length();i++)
             {
                 counter++;
                 if(i<=s.length()-1 && s[i]!=s[i+1])
                 {
                     res = res+to_string(counter)+s[i];
                     counter = 0;
                 }
             }
             
        
        return res;
    }
};