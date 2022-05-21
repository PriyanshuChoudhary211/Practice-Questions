class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>ans;
        vector<int>a;
        int r = mat.size();
        int c = mat[0].size();
        int x = 0; 
        for(int i = 0 ; i < r ; i++)
        {
            x=0;
            for(int j = 0 ; j < c; j++)
            {
                if(mat[i][j] == 1)
                    x++;
            }
            ans.push_back(make_pair(x,i));
        }
        sort(ans.begin(),ans.end());
        for(int i = 0 ; i<k;i++)
        {
            a.push_back(ans[i].second);
        }
        return a;
    }
};