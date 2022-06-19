class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,int> values;
        unordered_map<int,vector<pair<int,int>>> adjLis;
        for(auto i:times){
            adjLis[i[0]].push_back({i[1],i[2]});
        }
        for(int i=1;i<=n;i++) values[i]=INT_MAX;
        
        
        set<pair<int,int>> st;
        values[k]=0;
        st.insert({0,k});
        while(st.size()){
            auto tp=*(st.begin());
            int node=tp.second;
            int dis=tp.first;
            
            st.erase(tp);
            for(auto ngh:adjLis[node]){
                if(dis+ngh.second<values[ngh.first]){
                    
                    pair<int,int> p={values[ngh.first],ngh.first};
                    auto k=st.find(p);
                    if(k!=st.end()){
                        st.erase(p);
                    }
                    
                    values[ngh.first]=dis+ngh.second;
                    st.insert({values[ngh.first],ngh.first});
                }
            }
        }
        
        int ans=0;
        for(auto i:values){
            // cout<<i.first<<"->"<<i.second<<endl;
            if(i.second==INT_MAX) return -1;
            ans=max(ans,i.second);
        }
        
        return ans;
    }
};