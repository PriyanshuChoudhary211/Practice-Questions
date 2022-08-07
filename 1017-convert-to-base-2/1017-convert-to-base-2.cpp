class Solution {
public:
    string baseNeg2(int n) {
        if(n==0) return "0";
        string ans="";
      while(n!=1)
      {
          if(n%2==0)
          {
              ans='0'+ans;
          }
          else 
          {
              ans='1'+ans;
          }
          if(n>0) n=-(n/2);
          else n=((-n+1)/2);
      } 
        return "1"+ans;
    }
};