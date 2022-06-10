class Solution {
public:
    void sortIt(int i,int j,vector<vector<int>>& mat)
    {
        vector<int>s;
        int x = i,y = j;
        while(x<mat.size() && y<mat[0].size())
        {
            s.push_back(mat[x][y]);
            x++;
            y++;
        }
        sort(s.begin(),s.end());
        int k=0;
        while(i<mat.size() && j<mat[0].size())
        {
            mat[i][j] = s[k++];
            i++;
            j++;
        }
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        for(int i = 0 ; i<mat.size();i++)
        {
            sortIt(i,0,mat);
        }
        for(int j = 1; j<mat[0].size();j++)
        {
            sortIt(0,j,mat);
        }
        return mat;
    }
};