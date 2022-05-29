class Solution {
public:
    int titleToNumber(string s) {
        int ans=0;
        for(int i = s.size()-1,j=0;i>=0;i--,j++)
        {
             ans += pow(26,j)*(s[i]-64);
        }
        return ans;
    }
};