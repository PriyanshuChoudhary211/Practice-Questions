class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       int n = strs.size();
        string ans ="";
        int str_size=INT_MAX;
        for(int i = 0 ; i<n;i++)
        {
            string s = strs[i];
            int m = s.length();
            str_size = min(str_size,m);
         }
        string s = strs[0];
        for(int i = 0 ; i<str_size;i++)
        {
            for(int j = 1;j<n;j++)
            {
                string x = strs[j];
                if(s[i]!=x[i])
                    return ans;
            }
            ans+=s[i];
        }
        return ans;
    }
};