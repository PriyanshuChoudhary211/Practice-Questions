//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution {
public:
    bool dfs(int src, vector<int>&vis,vector<int>&pathVis,vector<pair<int,int>>adj[],int k, int s)
    {
        if(s>=k)return true;
        vis[src]=1;
        pathVis[src]=1;
        for(auto it:adj[src])
        {
            int n=it.first;
            int l=it.second;
            if(!vis[n] || pathVis[n]==0)
            {
              
                if(dfs(n,vis,pathVis,adj,k,s+l)) return true;
            }
        }
        pathVis[src]=0;
        return false;
    }
    bool pathMoreThanK(int V, int E, int k, int *a) 
    { 
      vector<pair<int,int>>adj[V];
      int i=0;
      while(i<E*3)
      {
          adj[a[i]].push_back({a[i+1],a[i+2]});
          adj[a[i+1]].push_back({a[i],a[i+2]});
          i+=3;
      }
    //   for(int i=0;i<V;i++)
    //   {
    //       for(auto it:adj[i])
    //       {
    //           cout<<i<<" "<<it.first<<" "<<it.second<<endl;
    //       }
    //   }
      vector<int>vis(V,0),pathVis(V,0);
      if(dfs(0,vis,pathVis,adj,k,0)) return true;
      return false;
    } 
};




//{ Driver Code Starts.


int main() {
	//code
    int t;cin >> t;
    while(t--)
    {
        int V, E, K;
        cin >> V >> E >> K;
        int a[3*E + 1];
        for(int  i=0;i<3*E;i++){
            cin >> a[i];
        }
        
        Solution obj;
        if(obj.pathMoreThanK(V, E, K, a)){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
        
    }
	return 0;
}
// } Driver Code Ends