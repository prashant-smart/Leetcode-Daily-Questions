class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> values(n+1,INT_MAX),k_values(n+1,INT_MAX);
        unordered_map<int,vector<vector<int>> > umap;
        for(auto iter:flights){
            umap[iter[0]].push_back({iter[2],iter[1]});
        }
        
        queue<vector<int>> que;
        que.push({0,0,src});
        values[src]=0;
        k_values[src]=0;
        while(que.size()){
            auto tp=que.front();
            int node=tp[2];
            int node_k=tp[0];
            int weight=tp[1];
            que.pop();
            if(node_k==k+1) continue;
            for(auto ngh:umap[node]){
                if(values[ngh[1]]<=weight+ngh[0]&&k_values[ngh[1]]<=node_k+1) continue;
                que.push({node_k+1,ngh[0]+weight,ngh[1]});
                values[ngh[1]]=min(values[ngh[1]],ngh[0]+weight);
                k_values[ngh[1]]=min(node_k+1,k_values[ngh[1]]);
            }
        }
        return values[dst]==INT_MAX?-1:values[dst];
        
    }
};