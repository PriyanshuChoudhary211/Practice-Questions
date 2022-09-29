class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>ans;
        auto it=lower_bound(arr.begin(),arr.end(),x);
        int j=it-arr.begin();
        int i=j-1;
        while(k && i>=0 && j<arr.size())
        {
            if(abs(arr[i]-x)<=abs(arr[j]-x))
            {
                ans.push_back(arr[i]);
                i--;
            }
            else if(abs(arr[i]-x)>abs(arr[j]-x))
            {
                ans.push_back(arr[j]);
                j++;
            }
            k--;
        }
        if(k>0)
        {
            while(k>0 && i>=0)
            {
                ans.push_back(arr[i]);
                i--;
                k--;
            }
            while(k>0 && j<arr.size())
            {
                ans.push_back(arr[j]);
                j++;
                k--;
            }
            
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};