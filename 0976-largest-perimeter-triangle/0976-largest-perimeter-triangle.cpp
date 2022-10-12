class Solution {
public:
    bool isValid(int a,int b,int c)
    {
        if(a+b>c && b+c>a && c+a>b)
            return true;
        return false;
    }
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int j=nums.size()-1;
        int i=j-2;
        while(i>=0)
        {
            if(isValid(nums[i],nums[i+1],nums[j])==true)
                return (nums[i]+nums[i+1]+nums[j]);
            i--;
            j--;
        }
        return 0;       
        
    }
};