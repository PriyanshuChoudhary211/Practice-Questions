class Solution {
public:
    string multiply(string num1, string num2) {
        int n=num1.length();
        int m=num2.length();
        if(num1=="0" || num2=="0") return "0";
        vector<int>arr(n+m,0);
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                int res=(num1[i]-'0') * (num2[j]-'0');
                arr[i+j+1]+=res;
                arr[i+j]+=arr[i+j+1]/10;
                arr[i+j+1]=arr[i+j+1]%10;
            }
        }
        string ans="";
        int i=0;
        while(arr[i]==0)i++;
        while(i<n+m) ans+=to_string(arr[i++]);
        return ans;
    }
};