class Solution {
public:
    double helper(unordered_map<string,vector<pair<string,double>>>& umap,string &b,unordered_set<string>&vis,string curr){
        
        vis.insert(curr);
        double ans=0;
        
        for(auto ngh:umap[curr]){
            if(ngh.first==b){
                return ngh.second;
            }
            if(!vis.count(ngh.first)){
                ans=max(ans,ngh.second*helper(umap,b,vis,ngh.first));
            }
        }
        
        return ans;
    }
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& q) {
        unordered_map<string,vector<pair<string,double>> >umap;
        for(int i=0;i<eq.size();i++){
            umap[eq[i][0]].push_back({eq[i][1],val[i]});
            umap[eq[i][1]].push_back({eq[i][0],1/(val[i]*1.0)});
        }
        vector<double> ans;
        for(auto i:q){
            string a=i[0],b=i[1];
            unordered_set<string> vis;
            double aa=helper(umap,b,vis,a);
            
            ans.push_back(aa==0?-1*1.0:aa);
        }
        return ans;
    }
};