class NumberContainers {
public:
    set<pair<int,int>> st;
    unordered_map<int,int> umap;
    NumberContainers() {
        
    }
    
    void change(int i, int n) {
        if(umap.count(i)){
            auto k=st.find({umap[i],i});
            
            st.erase(k);
        }
        umap[i]=n;
        st.insert({n,i});
        
    }
    
    int find(int n) {
        auto pr=st.lower_bound({n,INT_MIN});
        if(pr==st.end()||pr->first!=n) return -1;
        return pr->second;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */