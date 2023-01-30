//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        vector<int> minimumTime(int n,vector<vector<int>> &edges,int m)
        {
            vector<int>adj[n+1];
            vector<int>indegree(n+1,0);
            for(auto it:edges)
            {
                adj[it[0]].push_back(it[1]);
                indegree[it[1]]++;
            }
            queue<pair<int,int>>q;
            vector<int>ans(n,0);
            for(int i=1;i<n+1;i++)
            {
                if(indegree[i]==0)
                {
                    q.push({i,1});
                }
            }
            while(!q.empty())
            {
                auto it=q.front();
                q.pop();
                int node=it.first;
                int t=it.second;
                ans[node-1]=t;
                for(auto it:adj[node])
                {
                    indegree[it]--;
                    if(indegree[it]==0)
                        q.push({it,t+1});
                }
                
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int m;
        cin>>m;
        vector<vector<int>> edges(m,vector<int>(2));
        for(int i=0;i<m;i++)
            cin>>edges[i][0]>>edges[i][1];
        Solution s;
        vector<int> ans=s.minimumTime(n,edges,m);
        for(auto j:ans)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends