class Solution {
public:
    string reorganizeString(string s) {
        string res="";
        map<char,int>mp;
        for(auto it:s)
        {
            mp[it]+=1;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it:mp)
        {
            pq.push(make_pair(it.second,it.first));
        }
        while(pq.size()>1)
        {
            pair<int,char>top1 = pq.top();
            pq.pop();
            pair<int,char>top2 = pq.top();
            pq.pop();
            
            res += top1.second;
            res += top2.second;
             top1.first--;
             top2.first--;
            if(top1.first>0)
                pq.push(top1);
               
            if(top2.first>0)
                pq.push(top2);   
        }
        if(!pq.empty() && pq.top().first>1)
        {
            return "";
        }
        if(!pq.empty() && pq.top().first == 1)
        {
            res+=pq.top().second;
        }
        return res;
    }
};