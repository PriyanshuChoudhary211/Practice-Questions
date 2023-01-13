//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isValid(int i,int j, vector<vector<int>>&grid)
    {
        if(((i>=0 && i<grid.size()) && (j>=0 && j<grid[0].size())) && (grid[i][j]!=0))return true;
        return false;
    }
    int ans=-1;
    void bfs(vector<vector<int>>&grid,int i,int j,int x,int y)
    {
        queue<pair<pair<int,int>,int>>q;
        q.push({{i,j},0});
        grid[i][j]=0;
        
        int a1[]={-1,1,0,0};
        int a2[]={0,0,1,-1};
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int a=it.first.first;
            int b=it.first.second;
            int d=it.second;
            if(a==x && b==y) ans=d;
            for(int k=0;k<4;k++)
            {
                int na=a+a1[k];
                int nb=b+a2[k];
                if(isValid(na,nb,grid))
                {
                    q.push({{na,nb},d+1});
                    grid[na][nb]=0;
                }
            }
        }
    }
    int shortestPath(vector<vector<int>> &grid, pair<int, int> s,
                     pair<int, int> d) {
        int i=s.first;
        int j=s.second;
         bfs(grid,i,j,d.first,d.second);
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
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends