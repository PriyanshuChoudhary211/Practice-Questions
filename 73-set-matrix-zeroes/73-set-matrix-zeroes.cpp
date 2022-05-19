class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int>s1,s2;
        for(int i = 0 ; i<matrix.size();i++)
        {
            for(int j = 0; j<matrix[0].size();j++)
            {
                if(matrix[i][j] == 0)
                {
                    s1.insert(i);
                    s2.insert(j);
                }
            }
        }
        for(auto i : s1)
        {
            for(int j = 0; j<matrix[0].size();j++)
            {
                matrix[i][j] = 0;
            }
        }
         for(auto i : s2)
        {
            for(int j = 0; j<matrix.size();j++)
            {
                matrix[j][i] = 0;
            }
        }
    }
};