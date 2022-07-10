class Solution {
public:
    bool isPalindrome(int x) {
        
        long long n=0;
        long long m = x;
        if(x<0)
            return false;
        while(x!=0)
        {
            int rem = x%10;
            n = n*10+rem;
            x/=10;
        }
        if(n==m)
            return true;
        else return false;
    }
};