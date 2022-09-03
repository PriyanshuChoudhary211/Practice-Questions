class Solution {
public:
    void func(vector<int>& c, int t,int i,vector<vector<int>>&ans,vector<int>&temp,int &s)
    {
        if(s>t) return; 
        if(i>=c.size())
        {
            if(s==t)
            {
                ans.push_back(temp);
               
            }
            return;
        }
    
        temp.push_back(c[i]);
        s+=c[i];
        func(c,t,i,ans,temp,s);
        temp.pop_back();
        s-=c[i];
        func(c,t,i+1,ans,temp,s);
        
        return;
    
    }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        int n=c.size();
        vector<vector<int>>ans;
        vector<vector<int>>a;

        vector<int>temp;
        int s=0;
        func(c,t,0,ans,temp,s);
        // for(auto it:ans)
        // {
        //     a.push_back(it);
        // }
        return ans;
    }
};