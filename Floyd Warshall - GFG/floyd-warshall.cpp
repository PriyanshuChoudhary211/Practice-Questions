//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&m){
	    for(int i=0;i<m.size();i++)
	    {
	        for(int j=0;j<m[0].size();j++)
	        {
	            if(m[i][j]==-1)
	                m[i][j]=1e9;
	        }
	    }
	    for(int via=0;via<m.size();via++)
	    {
	        for(int i=0;i<m.size();i++)
	        {
	            for(int j=0;j<m[0].size();j++)
	            {
	                m[i][j]=min(m[i][j],m[i][via]+m[via][j]);
	            }
	        }
	    }
	     for(int i=0;i<m.size();i++)
	    {
	        for(int j=0;j<m[0].size();j++)
	        {
	            if(m[i][j]==1e9)
	                m[i][j]=-1;
	        }
	    }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends