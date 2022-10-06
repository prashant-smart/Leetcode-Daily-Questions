class TimeMap {
public:
    unordered_map<string,map<int,string>> umap;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        umap[key].insert({-1*timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(!umap.count(key)) return "";
        auto it=umap[key].lower_bound(-1*timestamp);
        return (*it).second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */