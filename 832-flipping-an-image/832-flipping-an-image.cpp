class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> image) {
       // vector<vector<int>>ans(n,vector<int>(n));
        for(int i = 0 ; i<image.size();i++)
        {
            for(int j = 0 ; j<image[0].size();j++)
            {
                if(image[i][j] == 0)
                    image[i][j] = 1;
                else
                    image[i][j]=0;
            }
                
        }
        for(int i = 0 ; i<image.size();i++)
        reverse(image[i].begin(),image[i].end());
        
        return image;
    
    }
};