class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for(auto it =nums.begin();it!=nums.end();++it)
        {
            if(*(it) == 0)
                nums.erase(it--);
          
        }
        int x = nums.size();
        while(x<n)
        { 
            nums.push_back(0);
            x++;
        }
    }
};