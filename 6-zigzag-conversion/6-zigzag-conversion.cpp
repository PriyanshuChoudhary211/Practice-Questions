class Solution {
public:
    string convert(string s, int r) {
        char arr[r][1000];
        string ans="";
        memset(arr,'#',sizeof(arr));
        int n = s.length();
        int i = 0;
        int k = 0,flag=0;
        int j = 0;
        while(k<n)
        {
            i=0;
            while(i<r)
            {
                arr[i][j] = s[k++];
                if(k>=s.length())
                {
                        flag=1;
                    break;
                }
                
                i++;
            }
            if(flag==1)
                break;
            i = r-2;
            j++;
            while(i>0)
            {
                arr[i][j] = s[k++];
                  if(k>=s.length())
                {
                        flag=1;
                    break;
                }
                
                i--;
                j++;
            }
            if(flag==1)
                break;
        }
        for(int i = 0; i<r;i++)
        {
            for(int m = 0; m<=j;m++)
                if(arr[i][m]!='#')
                  ans+=arr[i][m];
        }
        return ans;
        }
};