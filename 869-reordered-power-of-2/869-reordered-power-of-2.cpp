class Solution {
public:
    bool reorderedPowerOf2(int n) {       
        int x=0,y=1;
        while(y<=1e9)
        {
            int n1=n;
            map<int,int>mp1;
            while(n1>0)
            {
                int rem=n1%10;
                mp1[rem]++;
                n1/=10;
            }
            int t=y;
            while(t>0)
            {
                int rem=t%10;
                mp1[rem]--;
               // if(mp1[rem]<0) return false;
                t/=10;
            }
            int f=0;
            for(auto it:mp1)
            {
                if(it.second!=0)
                    f=1;
            }
            if(f==0)
                return true;
             
            y*=2;
          //mp1.insert(mp2.begin(),mp2.end());

        }
        return false;
    }
};