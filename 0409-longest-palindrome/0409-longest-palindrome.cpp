class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.length();
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        int res=0;
        for(auto it:mp)
        {
            if(it.second%2==0)
                res+=it.second;
            else if(it.second>1 && it.second%2!=0)
            {
                int c=it.second-1;
                mp[it.first]=1;
                res+=c;
            }
        }
        int one=0;
        for(auto it:mp)
        {
            if(one==0 && it.second==1)
            {
                res+=1;
                one =1;
                break;
            }
        }
        
        return res;
    }
    
};