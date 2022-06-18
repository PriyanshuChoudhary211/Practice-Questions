/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>>ans;
        int h = 1000;
        int l=1;
        for(int i = 1;i<1000;i++)
        {
            l=1;
            h=1000;
            while(l<=h)
            {
                int mid = (l+h)/2;
                int x = customfunction.f(i,mid);
                if(x==z)
                {
                    ans.push_back({i,mid});
                    break;
                }
                else if(x<z)
                {
                    l = mid+1;
                }
                else 
                {
                    h=mid-1;
                }
                    
            }
            if(customfunction.f(i,1)>z)
                break;
        }
        return ans;
    }
};