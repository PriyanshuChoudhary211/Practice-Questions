class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<int>ans;
        int arr[26];
        for(int i=0;i<s.length();i++)
        {
            arr[s[i]-'a']=i;
        }
        int prev = -1;
        int maxi = arr[s[0]-'a'];
        for(int i=0;i<s.length();i++)
        {

            if(arr[s[i]-'a']>maxi)
            {
                maxi = arr[s[i]-'a'];
            }
            if(i == maxi)
            {
                ans.push_back(maxi-prev);
                prev = maxi;
            }
        }
        return ans;        
    }
};