class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
         map<char,int>m2;
        for(auto it:magazine)
        {
            m2[it]+=1;
        }
        for(auto it:ransomNote)
        {
            m2[it]--;
            if(m2[it]<0)
                return false;
        }
        return true;       
        
    }
};