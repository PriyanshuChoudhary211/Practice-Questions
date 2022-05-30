class Solution {
public:
    int minOperations(vector<string>& a) {
        int ans=0;
        for(int i=0 ; i<a.size();i++)
        {
            if(a[i]=="../")
            {
               if(ans>0)
                 ans--;

            }
             else if(a[i]=="./")
               continue;
              else
               ans++;
            
        }
        
               return ans;
    }
};