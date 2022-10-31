class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& m) {
        int r=m.size();
        int c=m[0].size();
        int i=1,j=1;
        int k=0;
        for(int i=1;i<r;i++)
        {
            for(int j=1;j<c;j++)
            {
                if(m[i][j]!=m[i-1][j-1]) return false;
            
             }  
        }
        return true;
    }
};