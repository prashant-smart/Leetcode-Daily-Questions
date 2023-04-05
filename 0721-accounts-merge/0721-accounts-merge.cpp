class Solution {
public:
    
    void helper( unordered_map<int,unordered_set<int>>& umap,unordered_set<int>&vis,int curr,set<string>&ans,vector<vector<string>>& ac){
        for(int j=1;j<ac[curr].size();j++){
                auto ii=ac[curr][j];
                ans.insert(ii);
        }
        vis.insert(curr);
        for(auto ngh:umap[curr]){
            if(!vis.count(ngh)){
                helper(umap,vis,ngh,ans,ac);
            }
        }
        
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& ac) {
        unordered_map<string,unordered_set<int>> parent;
        for(int i=0;i<ac.size();i++){
             for(int j=1;j<ac[i].size();j++){
                auto ii=ac[i][j];
                parent[ii].insert(i);
            }
        }
        
        unordered_map<int,unordered_set<int>> umap;
        for(int i=0;i<ac.size();i++){
            for(int j=1;j<ac[i].size();j++){
                auto ii=ac[i][j];
                for(auto ik:parent[ii]){
                    if(ik!=i)
                        umap[i].insert(ik);
                }
            }
        }
        vector<vector<string>> ans;
        
        unordered_set<int> vis;
        for(int i=0;i<ac.size();i++){
            if(!vis.count(i)){
                set<string> v;
                helper(umap,vis,i,v,ac);
                vector<string> vv={ac[i][0]};
                for(auto kp:v){
                    vv.push_back(kp);
                }
                ans.push_back(vv);
            }
        }
        
        
        
        return ans;
        
    }
};