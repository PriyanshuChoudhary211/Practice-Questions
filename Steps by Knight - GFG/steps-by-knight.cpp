//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    bool isValid(int i,int j, int N)
    {
        if(i<1 || j<1 || i>N || j>N) return false;
        return true;
    }
	int minStepToReachTarget(vector<int>&kn,vector<int>&tp,int N)
	{
	   queue<pair<int,pair<int,int>>>q;
	   q.push({0,{kn[0],kn[1]}});
	   int s=N+1;;
	   vector<vector<int>>vis(s,vector<int>(s,0));
	   vis[kn[0]][kn[1]]=1;
	   while(!q.empty())
	   {
	       auto it=q.front();
	       q.pop();
	       int step=it.first;
	       int i=it.second.first;
	       int j=it.second.second;
	       if(i==tp[0] && j==tp[1]) return step;
	       int a1[]={1,1,2,2,-1,-1,-2,-2}; 
	       int a2[]={2,-2,1,-1,2,-2,-1,1}; 
	       for(int k=0;k<8;k++)
	       {
	           int ni=i+a1[k];
	           int nj=j+a2[k];
	           if(isValid(ni,nj,N))
	           {
	               if(!vis[ni][nj])
	               {
	                   vis[ni][nj]=1;
	                   q.push({step+1,{ni,nj}});
	               }
	           }
	       }
	   }
	   return -1;
	   
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends