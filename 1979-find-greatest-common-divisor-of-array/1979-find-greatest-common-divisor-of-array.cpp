class Solution {
public:
    int gcd(int a, int b)
    {
        return b==0?a:gcd(b,a%b);
    }
    int findGCD(vector<int>& nums) {
        return gcd(*(min_element(nums.begin(),nums.end())),*(max_element(nums.begin(),nums.end())));
        
    }
};