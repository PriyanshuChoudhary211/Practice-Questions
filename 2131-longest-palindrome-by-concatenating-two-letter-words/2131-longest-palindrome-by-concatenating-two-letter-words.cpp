class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;
        int ans=0;
        for(int i=0;i<words.size();i++)
        {   
            string rev="";
            rev+=words[i][1];
            rev+=words[i][0];
            if(mp.find(rev)==mp.end())
            {
                mp[words[i]]+=1;
            }
            else if(mp.find(rev)!=mp.end())
            {
                if(mp[rev]>0)
                {
                    ans+=4;
                    mp[rev]--;
                }
                else mp[words[i]]++;
            }
        } 
        for(auto it:mp)
        {
            if(it.second==1 && it.first[0]==it.first[1])
            {  ans+=2;
                break;
            }
        }
        for(auto it:mp)
            cout<<it.first<<" "<<it.second<<endl;
        return ans;
    }
};