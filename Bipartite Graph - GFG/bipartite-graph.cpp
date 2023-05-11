//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool check(vector<int>adj[],int V,vector<int>&vis,vector<int>&color,int i)
    {
        queue<int>q;
	    q.push(i);
	    vis[i]=1;
	    color[i]=0;
	    while(!q.empty())
	    {
	        int node=q.front();
	        q.pop();
	        for(auto it:adj[node])
	        {
	            if(!vis[it])
	            {
	                if(color[node]==0) color[it]=1;
	                else color[it]=0;
	                vis[it]=1;
	                q.push(it);
	            }
	            else if(color[it]==color[node])
	                return false;
	        }
	    }
	    return true;
	    
    }
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int>vis(V,0);
	    vector<int>color(V,0);
	    for(int i=0;i<V;i++)
	    {
	       if(!vis[i])
	       {
	           if(check(adj,V,vis,color,i)==false) return false;
	       }
	    }
	    return true;
	    
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends