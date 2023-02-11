//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int arr[], int N, int k)
    {
           map<int,int>mp;
            int ans=0;
            mp[ans]=1;
            int cur_sum=0;
            for(int i=0;i<N;i++)
            {
                cur_sum+=arr[i];
                if(mp.find(cur_sum-k)!=mp.end())
                {
                    ans+=mp[cur_sum-k];
                }
                mp[cur_sum]++;
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
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends