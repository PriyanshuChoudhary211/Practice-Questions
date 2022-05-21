class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int count = 0;
        int r = 0;
        int c = grid[0].size()-1;
        
        while(r<grid.size() && c>=0)
        {
            if(grid[r][c]<0)
            {
                count+=grid.size()-r;
                c--;
            }
            else if(grid[r][c]>=0)
            {
                r++;
            }
        }       
        return count;
    }
};