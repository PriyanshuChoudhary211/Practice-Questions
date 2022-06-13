class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end(),greater<int>());
        int c=1,ans=0;
        for(int i = 0 ; i<piles.size()/3;i++)
        {
            ans+=piles[c];
            c+=2;
        }
        return ans;            
    }
};