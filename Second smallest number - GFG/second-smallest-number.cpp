//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int S, int D){
        int size=0;
        string ans="";
        if(9*D<=S)return "-1";
        while(S>9 && size<D)
        {
            ans="9"+ans;
            size++;
            S-=9;
        }
        if(D-size==1)
        {
            ans=to_string(S)+ans;
        }
        else
        {
            string s="";
            s+='1';
            S-=1;
            size++;
            while(size<D-1)
            {
                s+='0';
                size++;
            }
            s+=to_string(S);
            ans=s+ans;
        }
        int i=ans.length()-1;
        if(ans[i]=='9')
        {
            while(ans[i]=='9')
            {
                i--;
            }
            ans[i]++;
            ans[i+1]--;
        }
        else
        {
            ans[i]--;
            ans[i-1]++;
        }
        if(size>D) return "-1";
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
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends