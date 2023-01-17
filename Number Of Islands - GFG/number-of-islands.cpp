//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class DisjointSet
{
    vector<int>rank,parent;
    int c;
    public:
    DisjointSet(int n)
    {
        c=0;
        rank.resize(n,0);
        parent.resize(n);
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
        if(ulp_u==ulp_v) return ;
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
    int findComponent()
    {
        for(int i=0;i<parent.size();i++)
        {
            if(parent[i]==i)
            c++;
        }
        return c;
    }
};
class Solution {
  public:
    bool isValid(int i, int j, vector<vector<int>>&vis)
    {
        if(i>=0 && i<vis.size() && j>=0 && j<vis[0].size()) return true;
        return false;
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &A) {
       vector<int>ans;
       DisjointSet obj(m*n);
       int cc=0;
       vector<vector<int>>vis(n,vector<int>(m,0));
       for(int i=0;i<A.size();i++)
       {
           int a=A[i][0];
           int b=A[i][1];
           if(vis[a][b])
           {
               ans.push_back(cc);
           }
           else
           {
               cc++;
               vis[a][b]=1;
               int a1[]={-1,1,0,0};
               int a2[]={0,0,-1,1};
               for(int i=0;i<4;i++)
               {
                   int na=a+a1[i];
                   int nb=b+a2[i];
                   if(isValid(na,nb,vis) && vis[na][nb])
                   {
                       int u=(na*m)+nb;
                       int v=(a*m)+b;
                       int ulp_u = obj.findUParent(u);
                       int ulp_v = obj.findUParent(v);
                       if(ulp_u==ulp_v) continue;
                       else
                       {
                           obj.unionByRank(u,v);
                           cc--;
                       }
                   }
               }
               ans.push_back(cc);
           }
       }
       return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends