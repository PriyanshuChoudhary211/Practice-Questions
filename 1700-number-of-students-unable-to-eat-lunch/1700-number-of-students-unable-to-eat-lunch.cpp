class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>q1,q2;
        for(auto it:students)
        {
            q1.push(it);
        }
        for(auto it:sandwiches)
        {
            q2.push(it);
        }
        int count=0;
        while(!q1.empty())
        {
            if(q1.front() == q2.front())
            {
                count=0;
                q1.pop();
                q2.pop();
            }
            else if(q1.front() != q2.front())
            {
                while(q1.front()!=q2.front() && count<q1.size())
                {
                    int x = q1.front();
                    q1.pop();
                    q1.push(x);
                    count++;    
                }
                if(count==q1.size())
                return q1.size();
            }
        }
        
        return 0;
    }
};