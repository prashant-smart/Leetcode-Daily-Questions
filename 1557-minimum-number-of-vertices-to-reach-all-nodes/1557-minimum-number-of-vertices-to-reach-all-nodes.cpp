class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_map<int,int>degree;
        
        for(auto i:edges){
            // umap[i[0]].push_back(i[1]);
            degree[i[1]]++;
        }
        
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!degree.count(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};