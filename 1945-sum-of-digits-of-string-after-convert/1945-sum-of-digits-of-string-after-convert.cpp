class Solution {
public:
    int getLucky(string s, int k) {
        int x=0;
        int sum=0;
        for(int i = 0 ; i<s.length();i++)
        {
            int x = s[i]-96;
            if(x<=9)
            {
                sum+=x;
            }
            else
            {
                while(x>0)
                {
                    int rem = x%10;
                    sum+=rem;
                    x/=10;
                }
            }
        }
        k--;
        int res;
        while(k>0)
        {
             res=0;
            while(sum>0)
            {
                int r = sum%10;
                res = res+r;
                sum/=10;
            }
            sum=res;
            k--;
        }
        return res;
    }
};