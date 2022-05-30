class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<char,int>m;
        int sum=0;
        for(auto it:stones)
            m[it]++;
        for(auto it:jewels)
        {
            sum += m[it];
        }
        return sum;
    }
};