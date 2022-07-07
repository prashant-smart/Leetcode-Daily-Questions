class Solution {
public:
    int helper(unordered_map<int,vector<int>>& umap,int node,unordered_set<int> &st){
        int ans=1;
        st.insert(node);
        for(auto ngh:umap[node]){
            if(!st.count(ngh)){
                ans+=helper(umap,ngh,st);
            }
        }
        return ans;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> umap;
        for(auto i:edges){
            umap[i[0]].push_back(i[1]);
            umap[i[1]].push_back(i[0]);
        }
        vector<int> vec;
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            if(!st.count(i)){
                vec.push_back(helper(umap,i,st));
            }
        }
        // cout<<"s";
        
        long long ans=0;
        long long sum=vec[0];
        for(int i=1;i<vec.size();i++){
            ans+=vec[i]*sum;
            sum+=vec[i];
        }
        return ans;
    }
};