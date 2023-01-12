//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    void bfs(vector<int>adj[],queue<int>&q,vector<int>&ans,int indeg[])
	{
	    while(!q.empty())
	    {
	        int it=q.front();
	        ans.push_back(it);
	        q.pop();
	        for(auto i:adj[it])
	        {
	            if(indeg[i]>0)
	            {
	                indeg[i]--;
	            }
	            if(indeg[i]==0)
	            {
	                q.push(i);
	            }
	        }
	    }
	}
    bool isCyclic(int V, vector<int> adj[]) {
         vector<int>ans;
	   int indeg[V]={0};
	   for(int i=0;i<V;i++)
	   {
	       for(auto it:adj[i])
	            indeg[it]++;
	   }
	   queue<int>q;
	   for(int i=0;i<V;i++)
	   {
	       if(indeg[i]==0)
	        q.push(i);
	   }
	   bfs(adj,q,ans,indeg);  
	    if(ans.size()==V) return false;
	    return true;
	
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends