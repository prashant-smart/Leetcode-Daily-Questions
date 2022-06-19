class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        if(start==end) return 0;
        unordered_map<int,double> dist;
        unordered_map<int,vector<pair<int,double>>> adjLis;
        for(int i=0;i<edges.size();i++){
            adjLis[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adjLis[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        for(auto i:adjLis) dist[i.first]=INT_MIN*1.0;
        unordered_map<int,bool> visited;
        set<pair<double,int>> st;
        st.insert({INT_MIN,start});
        
        dist[start]=1;
        
        while(st.size()){
            auto p=*(st.begin());
            int node=p.second;
            double val=dist[node];
            st.erase(st.begin());
            visited[node]=1;
            // cout<<node<<" ";
            for(auto ngh:adjLis[node]){
                
                if(val*ngh.second>dist[ngh.first]&&!visited[ngh.first]){
                    // cout<<node<<" "<<ngh.first<<" "<<val+ngh.second<<endl;
                    auto pr=st.find({-1*dist[ngh.first],ngh.first});
                    if(pr!=st.end()){
                        st.erase(pr);
                    }
                    dist[ngh.first]=val*ngh.second;
                    st.insert({-1*dist[ngh.first],ngh.first});
                }
            }
        }
        
        return (dist[end]==INT_MIN*1.0)?0:dist[end];
    }
};