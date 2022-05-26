class Solution {
public:
    
    void fun(vector<string>&ans,int sum, int n, string s)
    {
        if(n==0 && sum == 0)
        {
            ans.push_back(s);
            return;
        }
        if(sum>0)
        {
            fun(ans,sum-1,n,s+")");
        }
        if(n>0)
        {
            fun(ans,sum+1,n-1,s+"(");
        }
        
        
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        fun(ans,0,n,"");
        return ans;
    }
};