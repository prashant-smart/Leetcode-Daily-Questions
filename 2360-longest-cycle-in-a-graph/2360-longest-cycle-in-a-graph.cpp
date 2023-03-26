class Solution {
public:
    unordered_map<int,int> curr,vis;
    int ans=-1;
    
    
    void helper(unordered_map<int,vector<int>>& umap,int i,int cnt){
        vis[i]++;
        curr[i]=cnt;
        
        for(auto ngh:umap[i]){
            if(curr.count(ngh)){
                ans=max(ans,cnt-curr[ngh]+1);
            }else if (!vis.count(ngh)){
                helper(umap,ngh,cnt+1);
            }
        }
        curr.erase(i);
    }
    
    int longestCycle(vector<int>& edges) {
        unordered_map<int,vector<int>> umap;
        for(int i=0;i<edges.size();i++){
            if(edges[i]!=-1)
                umap[i].push_back(edges[i]);
        }
        
        
        for(int i=0;i<edges.size();i++){
            if(!vis.count(i)){
                helper(umap,i,1);
            }
        }
        return ans;
        
    }
};