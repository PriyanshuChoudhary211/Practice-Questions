//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int max_sum(vector<int>col_sum)
    {
        int currmaxi=0,ans=INT_MIN;
        for(int i=0;i<col_sum.size();i++)
        {
            currmaxi+=col_sum[i];
            ans=max(currmaxi,ans);
            if(currmaxi<0) currmaxi=0;
        }
        return ans;
    }
    void makeClear(vector<int>&col)
    {
        for(int i=0;i<col.size();i++)
            col[i]=0;
    }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
            vector<int>col_sum(R,0);
            int ans=INT_MIN;
            for(int i=0;i<C;i++)
            {
                makeClear(col_sum);
                for(int j=i;j<C;j++)
                {
                    for(int k=0;k<R;k++)
                    {
                        col_sum[k]+=M[k][j];
                    }
                    ans=max(ans,max_sum(col_sum));
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
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}
// } Driver Code Ends