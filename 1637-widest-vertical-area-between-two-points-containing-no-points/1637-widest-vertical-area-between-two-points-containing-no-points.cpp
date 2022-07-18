class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int>op,res;
        for(int i = 0; i<points.size();i++)
        {
            op.push_back(points[i][0]);
        }
        sort(op.begin(),op.end());
        int maxi=INT_MIN;
        for(int i = 0;i<op.size()-1;i++)
        {
            maxi = max(op[i+1]-op[i],maxi);
        }
        return maxi;
    }
};