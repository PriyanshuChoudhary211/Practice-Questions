class FrontMiddleBackQueue {
public:
    list<int>l1,l2;
    int s1,s2;
    FrontMiddleBackQueue() {
        s1=0;
        s2=0;
    }
    
    void pushFront(int val) {
        if(s1==0 && s2==0)
        {
            l2.push_front(val);
            s2++;
        }
       else if(s1<s2)
        {
            l1.push_front(val);
            s1++;
        }
        else
        {
            l2.push_front(l1.back());
            l1.pop_back();
            l1.push_front(val);
            s2++;
        }            
    }
    
    void pushMiddle(int val) {
        if(s1<s2)
        {
            l1.push_back(val);
            s1++;
        }
        else
        {
            l2.push_front(val);
            s2++;
        }
        
    }
    
    void pushBack(int val) {
        if(s1<s2)
        {
            l1.push_back(l2.front());
            l2.pop_front();
            s1++;
            l2.push_back(val);
        }
        else
        {
            l2.push_back(val);
            s2++;
        }       
                   
    }
    
    int popFront() {
        if(s1==0 && s2==0) return -1;
        else if(s1==0 && s2==1){
             int x = l2.front();
             l2.pop_front();
             s2--;
            return x;
        }
        else if(s1<s2)
        {
            l1.push_back(l2.front());
            l2.pop_front();
            s2--;
            int x = l1.front();
            l1.pop_front();
            return x;
        }
        else
        {
            int x = l1.front();
            l1.pop_front();
            s1--;
            return x;
        }
        
    }
    
    int popMiddle() {
        if(s1==0 && s2==0) return -1;
        else if(s1==0 && s2==1){
             int x = l2.front();
             l2.pop_front();
             s2--;
            return x;
        }
        else if(s1<s2)
        {
            int x = l2.front();
            l2.pop_front();
            s2--;
            return x;
        }
        else
        {
            int x = l1.back();
            l1.pop_back();
            s1--;
            return x;
        }
        
    }
    
    int popBack() {
         if(s1==0 && s2==0) return -1;
         else if(s1<s2)
         {
             int x = l2.back();
             l2.pop_back();
             s2--;
             return x;
         }
         else
         {
            int x = l2.back();
             l2.pop_back();
             l2.push_front(l1.back());
             l1.pop_back();
             s1--;
             return x;
         }
     
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */