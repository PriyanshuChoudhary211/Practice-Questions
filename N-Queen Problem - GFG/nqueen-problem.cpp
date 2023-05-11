//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<char>>ans;
    bool isSafe(vector<string>&board,int i, int j)
    {
        if(i>=board.size() || j>= board.size())return false;
        //row
        for(int k=0;k<board.size();k++)
        {
            if(board[k][j]=='Q')
                return false;
        }
        //col
        for(int k=0;k<=j;k++)
        {
            if(board[i][k]=='Q')
                return false;
        }
        int m=i,n=j;
        while(m>=0 && n>=0)
        {
            if(board[m][n]=='Q')
                return false;
            m--;
            n--;
        }
        m=i;n=j;
        while(m>=0 && n<board.size())
        {
              if(board[m][n]=='Q')
                return false;
            m--;
            n++;
        }
        return true;
        
    }
    void func(vector<vector<string>>&board,vector<string>&temp,int i)
    {
        int n=temp.size();
        if(i==n){
            board.push_back(temp);
            return;
        }
        for(int k=0;k<n;k++)
        {
           if(isSafe(temp,i,k))
           {
               temp[i][k]='Q';
               func(board,temp,i+1);
               temp[i][k]='.';
           }
        }
    }
    
    vector<vector<int>> nQueen(int n) {
        vector<vector<string>>ans;
        vector<vector<int>>res;
        string s="";
        for(int i=0;i<n;i++) s+='.';
        vector<string>temp(n,s);
        func(ans,temp,0);
        for(auto it:ans)
        {
            vector<int>temp;
            for(auto ti:it)
            {
                for(int j=0;j<ti.length();j++)
                {
                    if(ti[j]=='Q')
                    {
                        temp.push_back(j+1);
                    }
                }
            }
            res.push_back(temp);
            // cout<<endl;
        }
        return res;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends