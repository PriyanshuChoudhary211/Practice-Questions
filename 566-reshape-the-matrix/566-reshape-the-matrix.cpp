class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int row = mat.size();
        int col = mat[0].size();
        int matsize= row*col;
        int newmat = r*c;
         vector<vector<int>>ans(r,vector<int>(c));
        if(matsize == newmat)
        { 
            int m=0,n=0;
           
            for(int i = 0 ; i<row;i++)
            { 
                for(int j = 0 ; j<col;j++)
                {
                  if(m<r&&n<c)
                  {
                      ans[m][n] = mat[i][j];
                       if(n+1==c)
                      {
                          n=-1;
                          m++;
                      }
                      n++;
                     
                       
                  }
                  
                }
            }
        }
        else
            return mat;
        
        return ans;
    }
};