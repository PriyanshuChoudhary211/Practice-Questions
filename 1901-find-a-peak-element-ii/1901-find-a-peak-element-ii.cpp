class Solution {
public:
     int maxofRow(vector<int>& nums) {
       int j = 0;
         int maxi = INT_MIN;
         for(int i = 0 ; i<nums.size();i++)
         {
             if(maxi<nums[i])
             {
                 j = i;
                 maxi = nums[i];
             }
         }
         return j;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int i=0,j=0;
        vector<int>ans;
        for(int i = 0 ;i<mat.size();i++)
        {
            int j = maxofRow(mat[i]);
            if(i!=mat.size()-1 && mat[i][j]>mat[i+1][j])
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
            else if(i == mat.size()-1)
            {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }         
        }
        return ans;
    }
};