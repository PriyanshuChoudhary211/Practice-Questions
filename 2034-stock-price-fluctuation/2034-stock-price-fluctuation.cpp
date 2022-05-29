class StockPrice {
public:
   map<int,int>mp;
   map<int,int>freq;
    StockPrice() {
        
    }
    int time = INT_MIN;
    
    void update(int timestamp, int price) {
        if(mp.find(timestamp)!=mp.end())
        {
            int pre = mp[timestamp];
            freq[pre]--;
            if(freq[pre]==0)
                freq.erase(pre);
        }
        mp[timestamp] = price;
        freq[price]++;
        if(timestamp>time)
        {
            time = timestamp;
        }
        
    }
    int current() {
      return mp[time];
    }
    
    int maximum() {
        return freq.rbegin()->first;
    }
    
    int minimum() {
       return freq.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */