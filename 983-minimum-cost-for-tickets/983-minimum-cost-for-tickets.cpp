class Solution {
public:
    int func(vector<int>& days, vector<int>& costs,int ind,vector<int>&dp)
    {
        int n=days.size();
        if(ind==days.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int op1 = costs[0]+func(days,costs,ind+1,dp);
        int i;
        for(i=ind;i<n && days[i]<days[ind]+7;i++);
        int op2=costs[1]+func(days,costs,i,dp);
        
        int j;
        for(j=ind;j<n&&days[j]<days[ind]+30;j++);
        int op3=costs[2]+func(days,costs,j,dp);
            
        return dp[ind]=min(min(op1,op2),op3);
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size(),-1);
        return func(days,costs,0,dp);
    }
};