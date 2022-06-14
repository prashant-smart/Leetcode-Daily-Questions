class Solution {
public:
    
    void findAns(unordered_map< string,vector<pair<string,double>> >& adjLis,unordered_set<string>&visited,string curr,string& end,double & val,double pro){
        visited.insert(curr);
        
        if(end==curr){
            val=pro;
            return;
        }
        
        
        for(auto ngh:adjLis[curr]){
            if(!visited.count(ngh.first)){
                findAns(adjLis,visited,ngh.first,end,val,pro*ngh.second);
            }
        }
        
        
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> adjLis;
        
        for(int i=0;i<equations.size();i++){
            adjLis[equations[i][0]].push_back({equations[i][1],values[i]});
            adjLis[equations[i][1]].push_back({equations[i][0],(1.0/values[i])});
        }
        
        vector<double> ans;
        for(auto pair:queries){
            unordered_set<string> visited;
            double val=-1.00000;
            findAns(adjLis,visited,pair[0],pair[1],val,1.0);
            
            if(!adjLis.count(pair[0])||!adjLis.count(pair[1])) val=-1.00000;
            
            if(val<0){
                ans.push_back(-1.00000);
            }else ans.push_back(val);
        }
        return ans;
    }
};