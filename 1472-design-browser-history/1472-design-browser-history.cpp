class BrowserHistory {
public:
    stack<string>s,temp;
    BrowserHistory(string homepage) {
        s.push(homepage);
    }
    
    void visit(string url) {
        s.push(url);
        while(!temp.empty())
            temp.pop();
        
    }
    
    string back(int steps) {
        if(steps<s.size())
        {
            while(steps--)
            {
                temp.push(s.top());
                s.pop();
            }
            return s.top();
        }
        else{
            while(s.size()>1)
            {
                temp.push(s.top());
                s.pop();
            }
            return s.top();
        }
        return s.top();
    }
    
    string forward(int steps) {
        if(steps<=temp.size())
        {
            while(steps--)
            {
                s.push(temp.top());
                temp.pop();
            }
            
        }
        else
        {
            while(!temp.empty())
            {
                s.push(temp.top());
                temp.pop();
            }
        }
        return s.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */