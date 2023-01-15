//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
#define mod 100000
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int s, int e) {
        queue<pair<int,int>>q;
        q.push({0,s});
        vector<int>dist(99999,1e9);
        dist[s]=0;
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            auto dis=it.first;
            auto node=it.second;
            if(node==e) return dis;
            for(auto i:arr)
            {
                int val=(node*i)%mod;
                if(dist[val]>dis+1)
                {
                    dist[val]=dis+1;
                    q.push({dis+1,val});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends