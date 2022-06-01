class Solution {
public:
    string removeDuplicates(string s, int k) {
//         stack<pair<char,int>>st;
//         string ans = "";
//         for(auto it:s)
//         {
//             // int count=1;
//            if(!st.empty() && it == st.top().first)
//            {
//                auto it = st.top();
//                st.pop();
//                it.second++;
//                if(it.second!=k)
//                     st.push(it);
//            }
          
//             else
//                 st.push({it,1});
//         }
// //         while(!st.empty())
// //         {
            
// //             cout<<st.top().first<<" "<<st.top().second<<endl;
// //             st.pop();
// //         }
//         while(!st.empty())
//         {
//             auto it = st.top();
//             while(it.second--)
//               ans = st.top().first + ans;
//             st.pop();
//         }
//         return ans;        
//     // }
        int n = s.size();
        if(n<k) return s;
        
        stack<pair<char,int>> stk;
        for(int i=0; i<n; ++i){
            if(stk.empty() || stk.top().first != s[i]) stk.push({s[i],1});
            else{
                auto prev = stk.top();
                stk.pop();
                stk.push({s[i], prev.second+1});
            }
            if(stk.top().second==k) stk.pop();
        }
        
        string ans = "";
        while(!stk.empty()){
            auto cur = stk.top();
            stk.pop();
            while(cur.second--){
                ans.push_back(cur.first);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};