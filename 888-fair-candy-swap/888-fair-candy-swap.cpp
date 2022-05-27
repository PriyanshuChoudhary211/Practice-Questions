class Solution {
public:
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        vector<int>ans;
        int sum1=0,sum2=0;
        sum1 = accumulate(a.begin(),a.end(),0);
        sum2 = accumulate(b.begin(),b.end(),0);
        
        set<int>s;
        for(auto it:b)
        {
            s.insert(it);
        }
        int delta = (sum2-sum1)/2;
        for(int i = 0 ; i<a.size();i++)
        {
            int x = a[i]+delta;
            if(s.find(x)!=s.end())
            {
                ans.push_back(a[i]);
                ans.push_back(a[i]+delta);
                return ans;
            }
                
        }
        return ans;
        
        
        
    }
};