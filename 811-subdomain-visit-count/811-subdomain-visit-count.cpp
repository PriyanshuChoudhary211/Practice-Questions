class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cp) {
        vector<string>ans;
        map<string, int>mp;
        int x ;
        string y="";
        for(int i = 0; i<cp.size();i++)
        {
            y="";
             int j = 0;
             while(cp[i][j]!=' ')
             {
                 y+=cp[i][j];
                 j++;
             }
             x = stoi(y);
             j = cp[i].length()-1;
             y="";
             while(cp[i][j]!=' ')
             {
                 
                 if(cp[i][j]=='.')
                 {
                     mp[y]+=x;
                 }
                 y = cp[i][j]+y;
                 j--;
             }
             mp[y]+=x;
            
        }
        string a;
        int z;
        for(auto it:mp)
        { 
              z = it.second;
             a = to_string(z);
            a = a + ' ' + it.first;
           ans.push_back(a);
            a="";
        }
        
        return ans;
    }
};