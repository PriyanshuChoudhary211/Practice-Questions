class Solution {
public:
int maximumUniqueSubarray(vector<int>&a)
{
    int i = 0,j=0,mx=0,sum =0;
    unordered_set<int> s;
    while(j < a.size())
    {
        if(s.find(a[j]) == s.end())
        {
            sum = sum+a[j];
            s.insert(a[j]);
            j++;
        }
        else
        {
            mx = max(mx,sum);
            sum = sum - a[i];
            s.erase(a[i]);
            i++;
        }
    }
    mx = max(mx,sum); 
    return mx;
    }
};