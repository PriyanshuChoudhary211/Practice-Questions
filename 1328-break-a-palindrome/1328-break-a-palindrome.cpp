class Solution {
public:
    string breakPalindrome(string p) {
      if(p.length()==1)return "";
      if(p[0]!='a')
      {     p[0]='a';
       return p;
      }
       int j=0;
        while(j<p.length())
        {
            if(p[j]=='a')
             j++;
            else break;
        }
        
        if(j==p.length())
        {
            p[p.length()-1]='b';
           return p;
       }
      int size=p.length();
      if(size%2==0)
      {
          int i=0;
          while(i<=size/2)
          {
              
              if(p[i]>'a')
              {
                  p[i]='a';
                  return p;
              }
              i++;
          }    
      }
        else{
            int i=0;
            while(i<size/2)
            {
                if(p[i]>'a')
                {
                    p[i]='a';
                        return p;
                }
                i++;
            }
            p[size-1]='b';
        }
      
        return p;
    }
};