class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i = 0;
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>>ans;
        set<vector<int>>s;
        int x,k;
        int target = 0;
      for(;i<n-2;i++)
            {
         // if(i>0 && nums[i]==nums[i-1])continue;
                
                int j = i+1;
                k=n-1;
                x=target-nums[i];
               
                while(j<k)
                {
                 
                    if(nums[j]+nums[k] == x)
                    {
                        
                        vector<int>temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                         s.insert(temp);
                        if(nums[i]==nums[j])
                            break;
                        j++;
                    }
                    else if(nums[j]+nums[k]<x)
                        j++;
                    else k--;
                }
               
            }
        for(auto it: s)
        {
            ans.push_back(it);
        }
        return ans;
    }
};