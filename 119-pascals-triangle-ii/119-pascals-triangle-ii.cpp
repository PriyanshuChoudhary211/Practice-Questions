class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>r(rowIndex+1);
        for(int i = 0; i<=rowIndex;i++)
        {
            r[i].resize(i+1);
            r[i][0] = r[i][i] = 1;
            for(int j = 1; j<i;j++)
            {
                r[i][j] = r[i-1][j-1] + r[i-1][j];
            }
            
        }
        vector<int>ans;
        for(int i = 0 ; i<rowIndex+1;i++)
        {
            ans.push_back(r[rowIndex][i]);
        }
        
        return ans;
    }
};