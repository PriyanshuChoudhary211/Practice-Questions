class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s = 0,e = arr.size()-1;
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if(mid>0 && mid<arr.size()-1 && arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
                return mid;
            else if(mid<arr.size()-1 && arr[mid]<arr[mid+1])
              s = mid+1;
            else e = mid-1;
        }
        return -1;
    }
};