class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans(nums1.size()+nums2.size());
        merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),ans.begin());
       int n = ans.size();
        sort(ans.begin(),ans.end());
       if(n%2!=0)
           return ans[n/2];
       else
       {
           int k = n/2;
           double z = (ans[k]+ans[k-1])/2.0;
           return z;
       }
    }
    
};