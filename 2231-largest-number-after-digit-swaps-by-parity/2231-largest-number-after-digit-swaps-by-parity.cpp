class Solution {
public:
    int reverse(int num)
    {
        int rev = 0;
        while(num>0)
        {
            int r = num%10;
            num/=10;
            rev = rev*10 +r;
        }
        return rev;
    }
    int largestInteger(int num) {
        
        priority_queue<int>oq,eq;
        string s = to_string(num);
        int n = s.length();
        int x = num;
        while(x>0)
        {
            int rem = x%10;
            x/=10;
            if(rem % 2 == 0)
            {
                eq.push(rem);
            }
            else
            {
                oq.push(rem);
            }
        }
        
        int res = 0;
        for(int i = 0 ; i<n;i++)
        {
            int rem = s[i]-48;
            if(rem %2 == 0 && !eq.empty()){
                res = res*10 + eq.top();
                eq.pop();
            }
            else if(rem %2 != 0 && !oq.empty())
            {
                res = res*10 + oq.top();
                oq.pop();
            }
                
        }
        return res;        
    }
};