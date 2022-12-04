//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    string rearrange (string s, int N)
    {
       vector<int> vowel(26,0);

        vector<int> conso(26,0);
        int cv=0,cc=0;
        for(int i=0;i<N;i++){
            if(s[i]=='a' ||s[i]=='e'||s[i]=='o'||s[i]=='i'||s[i]=='u'){
                cv++;
                vowel[s[i]-'a']++;
            }
            else{
                cc++;
                conso[s[i]-'a']++;
            }
        }
        if(abs(cv-cc) >1)return "-1";
        
        string vow="", con="";
       for(int i=0; i<26; i++){
           if(vowel[i]!=0){
               vow+=char('a'+i);
               vowel[i]--;
               i--;
           }
       }

       for(int i=0; i<26; i++){
           if(conso[i]!=0){
               con+=char('a'+i);
               conso[i]--;
               i--;
           }
       }
        
        string ans="";
        if(cv>=cc){
            int j=0,k=0;
            for(int i=0;i<N; i++){
                if(i%2==1){
                    ans+=con[j];
                    j++;
                }
                else{
                    ans+=vow[k];
                    k++;
                }
            }
        }
        
        
         if(cv<cc){
            int j=0,k=0;
            for(int i=0;i<N; i++){
                if(i&1){
                    ans+=vow[j];
                    j++;
                }
                else{
                    ans+=con[k];
                    k++;
                }
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		Solution ob;
		cout << ob.rearrange (s, n) << endl;
	}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends