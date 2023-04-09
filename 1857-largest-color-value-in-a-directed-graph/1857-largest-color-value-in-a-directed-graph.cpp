class Solution {
public:
    unordered_set<int> currpath;
    unordered_map<int,vector<int> > umap;
    
    // unordered_map<char,int> freq,maxocc,vis;
    unordered_map<int,vector<int>> dp;
    
    string clr;
    bool ispossible=1;
    vector<int> helper(int curr){
        // cout<<curr<<" ";
        if(dp.count(curr)) return dp[curr];
       currpath.insert(curr);
        vector<int> v(27,0);
        v[clr[curr]-'a']++;
        vector<int> vv=v;
        
        
        
        // maxocc[clr[curr]]=max(fre[clr[curr]],maxocc[clr[curr]]);
        for(auto ngh:umap[curr]){
            if(currpath.count(ngh)){
                ispossible=0;
                return v;
            }
            else{
                auto temp=helper(ngh);
                
                for(int i=0;i<27;i++){
                    vv[i]=max(vv[i],v[i]+temp[i]);
                }
            }
        }
         v=vv;
        currpath.erase(curr);
        // if(curr==4) cout<<v[0]<<endl;
        return dp[curr]=v;
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        clr=colors;
        for(auto ngh:edges){
            umap[ngh[0]].push_back(ngh[1]);
        }
        int mx=0;
        for(int i=0;i<colors.length();i++){
            if(!dp.count(i)){
                auto vec=helper(i);
                // cout<<i<<endl;
                for(auto ii:vec){
                    // cout<<ii<<" "; 
                    mx=max(ii,mx);
                }
                // cout<<endl;
            }
        }
        if(!ispossible) return -1;
        return mx;
        
        
    }
};