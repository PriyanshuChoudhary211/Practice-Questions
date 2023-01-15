//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define mod 1000000007
class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
       vector<pair<int,int>>tym(n);
       for(int i=0;i<n;i++)
       {
           tym[i].first=1e9;
           tym[i].second=0;
       }
       vector<pair<int,int>>adj[n];
       for(int i=0;i<roads.size();i++)
       {
           adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
           adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
       }
       queue<pair<int,int>>q;
       q.push({0,0});
       tym[0].first=0;
       while(!q.empty())
       {
           auto it=q.front();
           q.pop();
           auto tm=it.first;
           auto node=it.second;
           for(auto i:adj[node])
           {
               if(tym[i.first].first>tm+i.second)
               {
                   tym[i.first].first=tm+i.second;
                   tym[i.first].second=1;
                   q.push({tym[i.first].first,i.first});
               }
               else if(tym[i.first].first==tm+i.second)
               {
                   tym[i.first].second=(tym[i.first].second+1)%mod;
                   q.push({tym[i.first].first,i.first});
               }
           }
       }
       return tym[n-1].second;
       
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends