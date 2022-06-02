class CustomStack {
public:
    stack<int>s;
    stack<int>temp;
    int st=0;
    int size;
    CustomStack(int maxSize) {
        size = maxSize;
    }
    
    void push(int x) {
        if(st<size)
        {
            s.push(x);
            st++;
        }   
    }
    
    int pop() {
        if(!s.empty())
        {
            int x = s.top();
            s.pop();
            st--;
            return x;
        }
        return -1;   
    }
    
    void increment(int k, int val) {
        if(s.size()<k)
        {
            while(!s.empty())
            {
                auto it = s.top();
                s.pop();
                it += val;
                temp.push(it);
            }
            while(!temp.empty())
            {
                s.push(temp.top());
                temp.pop();
            }
        }
        else
        {
              while(!s.empty())
              {
                auto it = s.top();
                s.pop();
                temp.push(it);
              }
              while(k--)
              {
                  int t = temp.top();
                  t+=val;
                  s.push(t);
                  temp.pop();
              }
            while(!temp.empty())
            {
                s.push(temp.top());
                temp.pop();
            }
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */