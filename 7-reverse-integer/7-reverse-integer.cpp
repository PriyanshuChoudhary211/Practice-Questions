class Solution {
public:
    int reverse(int x) {
        long m=0;
      
        while(x!=0)
        {
            int rem = x%10;
            m=m*10+rem;
            x/=10;
            
        }
          if(m>=2147483648 || m<=-2147483647)
              return 0;
        return m;
    }
};