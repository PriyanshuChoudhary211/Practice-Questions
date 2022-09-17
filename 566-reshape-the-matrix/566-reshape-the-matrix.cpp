class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<int>ans;
        if(mat.size() * mat[0].size()!=r*c) return mat;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
                ans.push_back(mat[i][j]);
        }
        vector<vector<int>>ans2;
        int k=0;
        for(int i=0;i<r;i++)
        {
            vector<int>temp;
            for(int j=0;j<c;j++)
            {
                temp.push_back(ans[k++]);                
            }
            ans2.push_back(temp);
        }
        return ans2;
    }
};