//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	int timer=1;
	bool dfs(vector<int>adj[],int low[],int tin[],int c, int d, vector<int>&vis,int src,int p)
	{
	    vis[src]=1;
	    low[src]=tin[src]=timer;
	    timer++;
	    for(auto it:adj[src])
	    {
	        if(it==p) continue;
	        else if(!vis[it])
	        {
	            if(dfs(adj,low,tin,c,d,vis,it,src)) return true;
	            low[src]=min(low[src],low[it]);
	            if(low[it]>tin[src])
	            {
	                if((it==c || it==d) && (src==d ||src==c)) return true;
	            }
	        }
	        else
	            low[src]=min(low[src],low[it]);
	    }
	    return false;
	}
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        int low[V];
        int tin[V];
        vector<int>vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
                if(dfs(adj,low,tin,c,d,vis,i,-1))return true;
        }
        return false;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends