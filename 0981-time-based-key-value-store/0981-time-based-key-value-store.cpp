class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> umap;
    // unordered_map<string,string> values;
    TimeMap() {
        
    }
    
    void set(string key, string value, int ts) {
        umap[key].push_back({ts,value});
    }
    
    string get(string key, int ts) {
        if(!umap.count(key)) return "";
        pair<int,string> pr={ts,""};
        auto pos=lower_bound(begin(umap[key]),end(umap[key]),pr);
        auto p=pos-begin(umap[key]);
        if(pos==end(umap[key])) return umap[key][p-1].second;
        if(umap[key][p].first>ts){
            if(p==0) return "";
            return umap[key][p-1].second;
        }
        return umap[key][p].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */