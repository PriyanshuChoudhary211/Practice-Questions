class Solution {
public:
    bool isPalindrome(string s) {
        string ans="";
        for(int i = 0 ; i<s.length();i++)
        {
            if(s[i] >='A' && s[i]<='Z')
                ans+=s[i]+32;
            else if(s[i]>='a' && s[i]<='z')
                ans+=s[i];
            else if(s[i]>='0' && s[i]<='9')
                ans+=s[i];
            
        }
        string x = ans;
        reverse(ans.begin(),ans.end());
        if(x==ans)
            return true;
        else return false;
    }
};