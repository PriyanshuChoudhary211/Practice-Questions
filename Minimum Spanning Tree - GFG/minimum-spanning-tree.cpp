//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>>arr;
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
                 arr.push_back({it[1],{i,it[0]}});
        }
       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
       int sum=0;
       pq.push({0,{0,-1}});
       vector<int>vis(V,0);
    //   vis[0]=1;
       while(!pq.empty())
       {
           auto it=pq.top();
           pq.pop();
           int wt=it.first;
           int node=it.second.first;
           int parent=it.second.second;
           if(vis[node]) continue;
           vis[node]=1;
           sum+=wt;
           for(auto it:adj[node])
           {
               if(!vis[it[0]])
               {
                  
                   pq.push({it[1],{it[0],node}});
               }
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