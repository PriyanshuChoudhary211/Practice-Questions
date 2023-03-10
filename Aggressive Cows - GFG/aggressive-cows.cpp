//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool checkIsValid(vector<int>&stalls,int dis,int cows)
    {
        int c=1,i=0,j=1;
        while(j<stalls.size())
        {
            if(stalls[j]-stalls[i]>=dis)
            {
                c++;
                i=j;
                j++;
            }
            else
                j++;
        }
        return c>=cows;
    }
    int solve(int n, int k, vector<int> &stalls) {
     sort(stalls.begin(),stalls.end());
     int st=0,en=stalls[stalls.size()-1]-stalls[0];
     int ans;
     while(st<=en)
     {
         int mid=st+(en-st)/2;
         if(checkIsValid(stalls,mid,k))
         {
             ans=mid;
             st=mid+1;
         }
         else
         {
             en=mid-1;
         }
     }
     return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends