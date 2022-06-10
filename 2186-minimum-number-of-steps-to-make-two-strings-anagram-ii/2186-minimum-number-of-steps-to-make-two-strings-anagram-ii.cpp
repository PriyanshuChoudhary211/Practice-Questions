class Solution {
public:
    int minSteps(string s, string t) {
        int count = 0;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int i = 0,j=0;
        while(i<s.length() && j<t.length())
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else if(s[i]<t[j])
            {
                i++;
                count++;
            }
            else 
            {
                j++;
                count++;
            }
        }
        while(i<s.length())
        {
            i++;
            count++;
        }
        while(j<t.length())
        {
            j++;
            count++;
        }
        return count;
    }
};