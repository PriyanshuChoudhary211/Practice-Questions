//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& pre) {
	    vector<int>adj[N];
	    int k=0;
	    for(auto it:pre)
	    {
	       adj[it.second].push_back(it.first);
	       
	    }
	    vector<int>indegree(N,0);
	    for(int i=0;i<N;i++)
	    {
	        for(auto it:adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    int c=0;
	    queue<int>q;
	    for(int i=0;i<N;i++)
	    {
	        if(indegree[i]==0)
	          {
	              q.push(i);
	              c++;
	          }
	    }
	    while(!q.empty())
	    {
	        int f=q.front();
	        
	        q.pop();
	        for(auto it:adj[f])
	        {
	             indegree[it]--;
	             if(indegree[it]==0)
	            {
	                q.push(it);
	                c++;
	            }
	        }
	    }
	    if(c==N) return true;
	    return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends