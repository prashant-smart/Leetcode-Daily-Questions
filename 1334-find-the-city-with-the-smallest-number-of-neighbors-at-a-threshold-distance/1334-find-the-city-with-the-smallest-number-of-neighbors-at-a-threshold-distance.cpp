class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int,vector<pair<int,int>>> adjLis;
        
        for(auto elm:edges){
            adjLis[elm[0]].push_back({elm[1],elm[2]});
            adjLis[elm[1]].push_back({elm[0],elm[2]});
        }
        
        map<int,int> cityWithNgh;
        for(int k=0;k<n;k++){
            unordered_map<int,int> values;
            for(int i=0;i<n;i++) values[i]=INT_MAX;
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
            // cout<<k<<"->";
            
            int cnt=0;
            for(auto i:values){
                // cout<<i.first<<" "<<i.second<<endl;
                if(i.second<=distanceThreshold&&k!=i.first)
                    cnt++;
            }
            cityWithNgh[k]=cnt;
        }
        // cout<<i.first<<"->"<<i.second<<endl;
        int mn=INT_MAX;
        int ans;
        for(auto i:cityWithNgh){ mn=min(mn,i.second);}
        // cout<<mn<<endl;
        for(auto i:cityWithNgh){
            if(i.second==mn){
                ans=i.first;
            }
        }
        return ans;
        
        
    }
};