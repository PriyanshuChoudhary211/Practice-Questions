class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gs) {
        vector<vector<int>>ans;
        int n = gs.size();
        vector<pair<int,int>>arr(n);
        for(int i = 0; i<gs.size();i++)
        {
            arr[i].first = gs[i];
            arr[i].second = i;
        }
        sort(arr.begin(),arr.end());
        vector<int>temp;
        for(int i =0;i<n;i++)
        {
            temp.push_back(arr[i].second);
            if(temp.size()==arr[i].first)
            {
                ans.push_back(temp);
                temp.clear();
            }
           
        }
        return ans;
    }
};