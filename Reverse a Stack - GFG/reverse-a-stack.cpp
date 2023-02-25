//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void insert(stack<int>&st,int temp)
    {
        if(st.empty())
        {
            st.push(temp);
            return;
        }
        int x=st.top();
        st.pop();
        insert(st,temp);
        st.push(x);
    }
    void reverse(stack<int>&st)
    {
        if(st.empty()) return;
        int temp=st.top();
        st.pop();
        reverse(st);
        insert(st,temp);
    }
    void Reverse(stack<int> &St){
      reverse(St);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends