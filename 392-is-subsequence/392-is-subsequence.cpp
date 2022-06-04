class Solution {
public:
    
   bool isSubSequence1(string s1, string s2)
{
    int n = s1.length(), m = s2.length();
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (s1[i] == s2[j])
            i++;
        j++;
    }
    return i == n;
}
    bool isSubsequence(string s,string t)
    {
        int n = s.length();
        int m = s.length();
        return isSubSequence1(s,t);
    }
};