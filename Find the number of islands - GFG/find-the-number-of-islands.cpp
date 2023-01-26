//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    bool isValid(vector<vector<char>>&grid,int i,int j)
    {
        if(i<0 || j<0 || i>=grid.size()|| j>=grid[0].size() || grid[i][j]=='0')return false;
        return true;
    }
    void dfs(vector<vector<char>>&grid,int i, int j)
    {
        int a1[]={-1,-1,-1,0,1,1,0,1};
        int a2[]={-1,0,1,-1,0,-1,1,1};
        grid[i][j]='0';
        for(int k=0;k<8;k++)
        {
            int na=i+a1[k];
            int nb=j+a2[k];
            if(isValid(grid,na,nb))
            {
                dfs(grid,na,nb);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int c=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    c++;
                    dfs(grid,i,j);
                }
            }
            
        }
        return c;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends