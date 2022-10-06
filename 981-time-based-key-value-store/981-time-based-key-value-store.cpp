class TimeMap {
public:
    unordered_map<string,string>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key+to_string(timestamp)]=value;
    }
    
    string get(string key, int t) {
        for(int i=t;i>=0;i--)
        {
            if(mp[key+to_string(i)]!="")
                return mp[key+to_string(i)];
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */