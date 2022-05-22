class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length()-1, x=0;
        int a = n;
        while(1)
        {
            if(s[n] == ' ')
            {
               
                n--;
                continue;
                
            }
            while(n>=0 && s[n]!=' ')
            {
                x++;
                n--;
            
            }
            break;
        }
        return x;
    }
};