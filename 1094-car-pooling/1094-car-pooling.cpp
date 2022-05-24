class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
         priority_queue<int,vector<int>,greater<int>>pick,drop;
         map<int,int>pick1,drop1;
        int max_d=INT_MIN;
         for(int i=0;i<trips.size();i++)
         {
             max_d = max(max_d,trips[i][2]);
             pick.push(trips[i][1]);
             drop.push(trips[i][2]);
             pick1[trips[i][1]]+=trips[i][0];
             drop1[trips[i][2]]+=trips[i][0];
         }
        int passenger=0;
        for(int i = 0 ; i<=max_d;i++)
        {
            if(!pick.empty() && i == pick.top())
            {
                passenger+=pick1[i];
                pick.pop();
            }
            while(!pick.empty() && i == pick.top())
                pick.pop();
            
            if(!drop.empty() && i == drop.top())
            {
                passenger-=drop1[i];
                drop.pop();
            }
            while(!drop.empty() && i == drop.top())
                drop.pop();
            if(passenger>capacity)
                return false;
        }
        return true;
        
            
        
    }
};