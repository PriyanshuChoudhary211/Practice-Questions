class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans; 
        int arr[n][n];
        for(int i = 0 ; i<n ; i++)
            arr[0][i] = 1;
        for(int i = 0 ; i<n ; i++)
            arr[i][0] = 1;
        for(int i = 1; i<n;i++)
        {
            for(int j = 1; j<=n-i-1;j++)
            {
                arr[i][j] = arr[i][j-1]+arr[i-1][j];
            }
        }
        for(int i = 0 ; i < n ; i++)
        {
            vector<int>temp;
            int k = i;
            int j = 0;
         //   temp.push_back(arr[i][j]);
            
            while(k>=0)
            {
                temp.push_back(arr[k][j]);
                k--;
                j++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};