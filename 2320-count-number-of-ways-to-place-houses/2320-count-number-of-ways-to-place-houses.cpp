#define mod 1000000007
class Solution {
public:
    
    int countHousePlacements(int n) {
       long long x=2,y=3;
        if(n==1) return x*x;
        if(n==2) return y*y;
        int t=0;
            long long temp;
       for(int i=3;i<=n;i++)
       {
           temp=(x%mod+y%mod)%mod;
           x=y;
           y=temp;
       }
        return (y%mod*y%mod)%mod;
    }
};