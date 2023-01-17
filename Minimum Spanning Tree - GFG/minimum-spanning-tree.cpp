//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet{
    vector<int>rank,parent;
    public:
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
        }
    }
    int findUParent(int node)
    {
        if(node==parent[node])
            return node;
        return parent[node]=findUParent(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int ulp_u=findUParent(u);
        int ulp_v=findUParent(v);
        if(ulp_u==ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v])
        {
            parent[ulp_u]=ulp_v;
        }
        else
        {
            parent[ulp_v]=ulp_u;
            rank[ulp_v]++;
        }
    }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>>edg;
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
            {
                edg.push_back({it[1],{it[0],i}});
            }
        }
        sort(edg.begin(),edg.end());
        int sum=0;
        DisjointSet obj(V);
        for(auto it: edg)
        {
            int u=it.second.first;
            int v=it.second.second;
            int ulp_u=obj.findUParent(u);
            int ulp_v=obj.findUParent(v);
            if(ulp_u==ulp_v) continue;
            else
            {
                obj.unionByRank(u,v);
                sum+=it.first;
            }
            
        }
        return sum;
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends