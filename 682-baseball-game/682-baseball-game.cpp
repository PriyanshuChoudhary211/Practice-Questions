class Solution {
public:
    int calPoints(vector<string>& arr) {
        vector<int>ans;
        int sum=0;
         for(int i =0 ; i<arr.size();i++)
         {
            
             if(arr[i]=="C")
             {
                 ans.pop_back();
             }
             else if(arr[i]=="D")
             {
                 int x = ans[ans.size()-1];
                 ans.push_back(x*2);
             }
             else if(arr[i]=="+")
                 ans.push_back(ans[ans.size()-1] + ans[ans.size()-2]);
             else
             {
                 int x = stoi(arr[i]);
                 ans.push_back(x);
             }
                 
         }
        return accumulate(ans.begin(),ans.end(),0);
    }
};