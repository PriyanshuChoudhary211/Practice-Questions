class Solution {
public:
    string addStrings(string num1, string num2) {
        int n=num1.length()-1;
        int m=num2.length()-1;
        int c=0;
        string s="";
        while(n>=0 &&m>=0)
        {
            int a=num1[n]-48;
            int b=num2[m]-48;
            
            if(a+b+c<=9)
            {
                s=to_string(a+b+c)+s;
                c=0;
            }
            else if(a+b+c>9)
            {
                int rem=(a+b+c)%10;
                c=1;
                s=to_string(rem)+s;
            }  
            n--;
            m--;
        }
        while(n>=0)
        {
            int a=num1[n]-48;
            if(a+c<=9)
            {
                s=to_string(a+c)+s;
                c=0;
            }
            
            else if(a+c>9)
            {
                int rem=(a+c)%10;
                c=1;
                s=to_string(rem)+s;
            }
            n--;
        }
         while(m>=0)
        {
            int a=num2[m]-48;
            if(a+c<=9)
            {
                s=to_string(a+c)+s;
                c=0;
            }
            else if(a+c>9)
            {
                int rem=(a+c)%10;
                c=1;
                s=to_string(rem)+s;
            }
            m--;
        }
        if(c==1)
            s=to_string(c)+s;
        return s;
    }
};