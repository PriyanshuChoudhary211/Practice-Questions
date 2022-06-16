class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
      int n = h.size();
        int la[n];
        int ra[n];
        stack<int>s;
        
        for(int i =0;i<n;i++)
        {
            while(!s.empty() && h[i]<=h[s.top()])
            {
                s.pop();
            }
            if(s.empty()==true)
            {
                la[i]=-1;
            }
            else la[i]=s.top();
            
            s.push(i);
        }
        while(!s.empty()) s.pop();
         for(int i =n-1;i>=0;i--)
        {
            while(!s.empty() && h[i]<=h[s.top()])
            {
                s.pop();
            }
            if(s.empty()==true)
            {
                ra[i]=n;
            }
            else ra[i]=s.top();
            s.push(i);
        }
        int ans=INT_MIN;
        for(int i =0;i<n;i++)
        {
            ans = max(ans,((ra[i]-la[i]-1)*h[i]));
        }
        
        return ans;
    }
};