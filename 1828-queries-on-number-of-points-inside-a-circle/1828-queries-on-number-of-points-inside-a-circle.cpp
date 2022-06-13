class Solution {
public:
    bool onBorder(int x,int y,int a,int b,int r)
    {
        int res = pow((x-a),2)+pow(y-b,2);
        if(res <= r*r)
            return true;
        return false;
    }
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
       int n = queries.size(),c=0;
         vector<int>ans;
        for(int i = 0 ; i<n;i++)
        {
            c=0;
            for(int j = 0; j<points.size();j++)
            {
                if(onBorder(queries[i][0],queries[i][1],points[j][0],points[j][1],queries[i][2])==true)
                    c++;
            }
            ans.push_back(c);
        }
        return ans;
    }
};