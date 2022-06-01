class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int>s;
        vector<int>res;
        vector<int>arr(prices.size());
        for( int i=0; i<prices.size();i++)
        {
            if(s.empty() || prices[s.top()]<prices[i])
            {
                s.push(i);
            }
            else
            {
                while(!s.empty() && prices[s.top()]>=prices[i])
                {
                    arr[s.top()] = prices[i];
                    s.pop();
                    
                }
                s.push(i);
            }
        }
        for(int i = 0 ; i<prices.size();i++)
        {
            res.push_back(prices[i]-arr[i]);
        }
        return res;
        
        
    }
};