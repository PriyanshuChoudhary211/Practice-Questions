class Solution {
public:
    int minCost(string c, vector<int>& nt) {
        int n=c.length();
        int s=nt.size();
        int i=0,j=1;
        if(n==1) return 0;
        int sum=accumulate(nt.begin(),nt.end(),0);
        int ans=0;
        while(j<n)
        {
            int maxi=nt[i];
            while(c[i]==c[j])
            {
                maxi=max(maxi,nt[j]);
                i++;
                j++;
            }
            if(c[i]!=c[j])
            {
                ans+=maxi;
                i++;
                j++;
            }
        }
        if(c[n-1]!=c[n-2])
            ans+=nt[s-1];
        
        return sum-ans;
    }
};