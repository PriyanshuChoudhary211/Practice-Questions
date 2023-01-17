//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class DisjointSet
{
    vector<int>parent,rank;
    int c=0;
    public:
    DisjointSet(int n)
    {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }
    int findUParent(int node)
    {
        if(node==parent[node]) return node;
        return parent[node]=findUParent(parent[node]);
    }
    void unionByRank(int u,int v)
    {
        int ulp_u=findUParent(u);
        int ulp_v=findUParent(v);
        if(ulp_u==ulp_v) return;
        if(ulp_u<ulp_v)
        {
            parent[ulp_u]=ulp_v;
        }
        else
        {
            parent[ulp_v]=ulp_u;
            rank[ulp_v]++;
        }
    }
    int findComponent(int n)
    {
        for(int i=0;i<n;i++)
        {
            if(parent[i]==i)
            c++;
        }
        return c;
    }
};
class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        DisjointSet obj(V);
       for(int i=0;i<adj.size();i++)
       {
           for(int j=0;j<adj.size();j++)
           {
               if(adj[i][j]==1)
               {
                   int ulp_i=obj.findUParent(i);
                   int ulp_j=obj.findUParent(j);
                   if(ulp_i==ulp_j) continue;
                   else
                   {
                       obj.unionByRank(i,j);
                   }
               }
           }
       }
       int ans=obj.findComponent(V);
       return ans;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends