class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
     priority_queue<pair<double,pair<int,int>> >q;
      for(int i = 0; i<classes.size();i++)
      {
          int p = classes[i][0];
          int t = classes[i][1];
          double d = (double)(p+1)/(t+1) - (double)(p)/(t);
          q.push({d,{p,t}});
      }
        while(extraStudents--)
        {
            int p = q.top().second.first;
            int t = q.top().second.second;
            p+=1;
            t+=1;
            q.pop();
            double d = (double)(p+1)/(t+1) - (double)(p)/(t);
             q.push({d,{p,t}});
        }
        double res=0;
        while(!q.empty())
        {
            res+=(double)q.top().second.first/q.top().second.second;
            q.pop();
        }
        
        return res/classes.size();
    }
};