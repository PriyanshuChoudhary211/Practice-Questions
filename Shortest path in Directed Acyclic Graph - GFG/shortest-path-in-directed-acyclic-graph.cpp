//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void toposort(vector<pair<int,int>>adj[],stack<int>&st,int src,int vis[])
    {
        vis[src]=1;
        for(auto it: adj[src])
        {
            if(!vis[it.first])
            {
                toposort(adj,st,it.first,vis);
            }
            
        }
        st.push(src);
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
      vector<pair<int,int>>adj[N];
      vector<int>ans(N,1e9);
      for(int i=0;i<M;i++)
      {
          adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
      }
    //   for(int i=0;i<N;i++)
    //   {
    //       cout<<i<<" --> ";
    //       for(auto it:adj[i])
    //       {
    //         cout<<"{"<<it.first<<" "<<it.second<<"} ";
    //       }
    //       cout<<endl;
    //   }
      stack<int>st;
      int vis[N]={0};
      for(int i=0;i<N;i++)
      {
          if(!vis[i])
            toposort(adj,st,i,vis);
      }
      vector<int>topo;
      while(!st.empty()){
          topo.push_back(st.top());
          st.pop();
      }
    //   for(auto it:topo) cout<<it<<" ";
      ans[0]=0;
      for(int i=0;i<topo.size();i++)
      {
          int f=topo[i];
          for(auto it:adj[f])
            ans[it.first]=min(ans[it.first],ans[f]+it.second);
      }
      for(int i=0;i<topo.size();i++){
          if(ans[i]==1e9) ans[i]=-1;
      }
      return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends