class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        set<int>s,s2;
        for(int i = 0 ; i<matrix.size();i++)
        {
             s.clear();
             s2.clear();

            for(int j = 0 ; j<matrix[i].size();j++)
            {
                s.insert(matrix[i][j]);
                s2.insert(matrix[j][i]);
            }
            if(s.size() != matrix.size()|| s2.size()!=matrix.size())
                return false;
           
        }
        return true;
    }
};