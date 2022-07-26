class Solution {
public:
    bool isPali(string &s)
    {
       int i=0,j=s.length()-1;
        while(i<j)
        {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int func(int i,int j,string &s,vector<int>&dp)
    {
        string temp="";
        if(i==s.length())return 0;
        if(dp[i]!=-1) return dp[i];
        int mini=INT_MAX;
        for(int ind=i;ind<=s.length()-1;ind++)
        {
            temp+=s[ind];
            if(isPali(temp))
            {
                int ans=1+func(ind+1,j,s,dp);
                  mini=min(mini,ans);
            }
        }  
        return dp[i]=mini;
    }
    int minCut(string s) {
        vector<int>dp(s.length(),-1);
        return func(0,s.length()-1,s,dp)-1;
    }
};