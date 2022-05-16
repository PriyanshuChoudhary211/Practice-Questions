class MinStack {
public:
    multiset<int>s;
    vector<int>ans;
    MinStack() {
        
    }
    void push(int val) {
        ans.push_back(val);
        s.insert(val);
    }
    
    void pop() {
        s.erase(s.find(ans[ans.size()-1]));
        ans.pop_back();
        
    }
    
    int top() {
        return ans[ans.size()-1];
    }
    
    int getMin() {
        return *(s.begin());
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */