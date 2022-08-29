class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>arr(m,-1);
        
        for(int i=0;i<m;i++)
        {
            int x=0,y=i;
            while(true)
            {
                if(x>=n)
                {
                    if(y>=0 && y<m)
                      arr[i]=y;
                    
                    break;
                }
                if(y+1<m && grid[x][y]==1 && grid[x][y+1]==1)
                {
                    x++;
                    y++;
                }
                else if(y-1>=0 && grid[x][y]==-1 && grid[x][y-1]==-1)
                {
                    x++;
                    y--;
                }
                else break;      
            }
            
        }
        return arr;
    }
};