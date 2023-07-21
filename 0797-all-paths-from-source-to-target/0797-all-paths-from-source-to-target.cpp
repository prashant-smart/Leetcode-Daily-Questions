class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int> temp,vector<vector<int>>& graph,int i){
        if(i>=graph.size()){
          return;  
        }
        temp.push_back(i);
        if(i==graph.size()-1){
            ans.push_back(temp);
        }
        
        for(auto iter:graph[i]){
            helper(temp,graph,iter);
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> temp;
        helper(temp,graph,0);
        return ans;
    }
};