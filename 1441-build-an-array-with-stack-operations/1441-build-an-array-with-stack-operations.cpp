class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>s;
        int k = 0;
        for(int i = 1; i<=n;i++)
        {
            if(k<target.size() && target[k]==i)
            {
                   s.push_back("Push");
                   k++;
                if(k==target.size()) break;
            }
            else
            {
                s.push_back("Push");
                s.push_back("Pop");
            }
        }
        return s;
    }
};