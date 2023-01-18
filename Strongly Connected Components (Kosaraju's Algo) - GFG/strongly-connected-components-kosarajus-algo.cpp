//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void topologicatSort(vector<int>adj[],stack<int>&st,int src,vector<int>&vis)
	{
	    vis[src]=1;
	    for(auto it:adj[src])
	    {
	        if(!vis[it])
	        {
	            topologicatSort(adj,st,it,vis);
	        }
	    }
	    st.push(src);
	}
	void dfs(vector<int>adj[],int src,vector<int>&vis)
	{
	    vis[src]=1;
	    for(auto it:adj[src])
	    {
	        if(!vis[it])
	        {
	            dfs(adj,it,vis);
	        }
	    }
	}
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int>vis(V);
        stack<int>st;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                topologicatSort(adj,st,i,vis);
            }
        }
       vector<int>adj2[V];
       for(int i=0;i<V;i++)
       {
           for(auto it:adj[i])
           {
               adj2[it].push_back(i);
           }
       }
       int c=0;
       vector<int>vis2(V,0);
       while(!st.empty())
       {
           int v=st.top();
           st.pop();
           if(!vis2[v])
           {
               c++;
               dfs(adj2,v,vis2);
           }
       }
      
        return c;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends