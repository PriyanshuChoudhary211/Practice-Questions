//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       stack<pair<int,int>>st;
       vector<int>ans;
       ans.push_back(1);
       st.push({price[0],1});
       int i=1;
       while(i<n)
       {
           if(price[i]<st.top().first)
           {
               ans.push_back(1);
               st.push({price[i],1});
           }
           else
           {
               int c=1;
               while(!st.empty() && price[i]>=st.top().first)
               {
                   c+=st.top().second;
                   st.pop();
                   
               }
               ans.push_back(c);
               st.push({price[i],c});
           }
           i++;
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
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends