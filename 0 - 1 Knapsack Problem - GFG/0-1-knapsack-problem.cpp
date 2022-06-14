// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       vector<vector<int>>dp(n,vector<int>(w+1,0));
       for(int i=wt[0];i<=w;i++){
           dp[0][i] = val[0];
       }
       for(int i=1;i<n;i++)
       {
           for(int j = 1; j<=w; j++)
           {
               int np = 0+dp[i-1][j];
               int p = -1;
               if(wt[i]<=j)
               {
                   p = val[i] + dp[i-1][j-wt[i]];
               }
               dp[i][j] = max(p,np);
           }
       }
       return dp[n-1][w];
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends