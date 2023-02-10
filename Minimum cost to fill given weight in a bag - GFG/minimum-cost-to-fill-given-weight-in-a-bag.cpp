//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
	public:
	int find(int cost[],int i,int N,int W, vector<vector<int>>&dp)
	{
	    if(W==0) return 0;
	    if(i>=N || W<0) return 1e9;
	    if(dp[i][W]!=-1)return dp[i][W];
	    int np=find(cost,i+1,N,W,dp);
	    int p=1e9;
	    if(cost[i]!=-1)
	    {
	        p=cost[i]+find(cost,i,N,W-(i+1),dp);
	    }
	    return dp[i][W]=min(p,np);
	}
	int minimumCost(int cost[], int N, int W) 
	{ 
	    vector<vector<int>>dp(N+1,vector<int>(W+1,-1));
	    int x=find(cost,0,N,W,dp);
        if(x==1e9) return -1;
        return x;
        
	} 
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends