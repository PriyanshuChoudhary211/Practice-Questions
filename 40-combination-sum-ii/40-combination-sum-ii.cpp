class Solution {
public:
    vector<vector<int>>ans;
    vector<int>temp;
    void func(vector<int>&c,int t,int i,int s)
    {
        if(s>t) return;
        if(s==t)
            {
                ans.push_back(temp);
                return ;
            }
        if(i==c.size())
        {
           return;
        }
       
        for(int ind=i;ind<c.size();ind++)
        {
            if(ind>i && c[ind]==c[ind-1])
                continue;
            if(s+c[ind]<=t)
            {
               temp.push_back(c[ind]);
                func(c,t,ind+1,s+c[ind]);
               temp.pop_back();            

            }   
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        int n=c.size();
        sort(c.begin(),c.end());
       func(c,t,0,0);
        return ans;
    }
};