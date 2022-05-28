typedef unsigned long long int ull;

ull findnthuglyNumber(int n){
    
    priority_queue<ull,vector<ull>,greater<ull>> pq;
    
    pq.push(1);
    unordered_set<ull> st;
    st.insert(1);
    while(n !=  0){
        n--;
        if(n == 0)  return pq.top();
        
        ull t = pq.top();
        pq.pop();
        if(st.find(t*2) == st.end()){
            st.insert(t*2);
            pq.push(t*2);
        }
        
        if(st.find(t*3) == st.end()){
            st.insert(t*3);
            pq.push(t*3);
        }
        
        if(st.find(t*5) == st.end()){
            st.insert(t*5);
            pq.push(t*5);
        }
    }
    return 0;
}

class Solution {
public:
    int nthUglyNumber(int n) {
        return findnthuglyNumber(n);
    }
};