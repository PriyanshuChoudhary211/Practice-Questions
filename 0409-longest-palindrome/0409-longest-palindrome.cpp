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
         int one=0;
        for(auto it:mp)
        {
            if(it.second%2==0)
                res+=it.second;
            else
            {
                int c=it.second-1;
                // mp[it.first]=1;
                res+=c;
                one = 1;
            }
        }
       
        // for(auto it:mp)
        // {
        //     if(one==0 && it.second==1)
        //     {
        //         res+=1;
        //         one =1;
        //         break;
        //     }
        // }
        
        if(one==1) return res+1;
        return res;
    }
    
};