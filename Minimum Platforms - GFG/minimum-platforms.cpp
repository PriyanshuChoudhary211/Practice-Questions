//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        vector<pair<int,int>>vec;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++)
        {
            vec.push_back({arr[i],dep[i]});
        }
        sort(vec.begin(),vec.end());
        int noOfPlatform=0,noOfTrain=0;
        pq.push(vec[0].second);
        noOfPlatform+=1;
        noOfTrain+=1;
        for(int i=1;i<n;i++)
        {
            while(!pq.empty() && vec[i].first>pq.top())
            {
                pq.pop();
                noOfTrain--;
            }
            if(!pq.empty() && vec[i].first<=pq.top())
            {
                if(noOfTrain==noOfPlatform)
                {
                    noOfPlatform++;
                }
                pq.push(vec[i].second);
                noOfTrain++;
                
            }
            else if(pq.empty())
            {
                pq.push(vec[i].second);
                noOfTrain++;
            }
        }
        return noOfPlatform;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends