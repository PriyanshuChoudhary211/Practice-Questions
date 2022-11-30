//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int n,vector<int>adj[],int vis[],vector<int>&ls)
    {
        vis[n]=1;
        ls.push_back(n);
        for(auto it:adj[n])
        {
            if(vis[it]!=1)
            {
                dfs(it,adj,vis,ls);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
         vector<int>ls;
         int s=0;
         int vis[V]={0};
         dfs(s,adj,vis,ls);
         return ls;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends