//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/

    int dp[201][201];
    bool find(string pattern, string str,int i, int j)
    {
        if(i==pattern.length() && j==str.length())return true;
        if(i==pattern.length() && j!=str.length())return false;
        if(j==str.length())
        {
            while(i<pattern.length())
            {
                if(pattern[i++]!='*')return false;
            }
            return true;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        bool p1=false,p2=false,p3=false,p4=false;
        if(pattern[i]=='*')
        {
            p1=find(pattern,str,i+1,j+1);
            p2=find(pattern,str,i,j+1);
            p3=find(pattern,str,i+1,j);
        }
        else if(pattern[i]=='?' || pattern[i]==str[j])
        {
            p1=find(pattern,str,i+1,j+1);
        }
        else return false;
        
        return dp[i][j] = p1|p2|p3;
    }
    int wildCard(string pattern,string str)
    {
        memset(dp,-1,sizeof(dp));
        int i=0,j=0;
        return find(pattern,str,0,0);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends