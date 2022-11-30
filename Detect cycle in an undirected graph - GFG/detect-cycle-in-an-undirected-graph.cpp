//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs(vector<int>&vis, vector<int>adj[],int n,int p)
    {
        vis[n]=1;
        for(auto it: adj[n])
        {
            if(vis[it]==0)
            {
                if(dfs(vis,adj,it,n)) return true;
            }
            else if(it!=p) return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int>vis(V);
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
                if(dfs(vis,adj,i,-1))return true;
        }
        return false;
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends