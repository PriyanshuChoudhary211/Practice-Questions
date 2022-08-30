class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int c=0;
        for(int i=0;i<n-1;i++)
        {
            int diff=nums[i+1]-nums[i];
            for(int j=i+1;j<n-1;j++)
            {
                if(nums[j+1]-nums[j]==diff)
                    c++;
                else break;
            }
        }
        return c;
    }
};