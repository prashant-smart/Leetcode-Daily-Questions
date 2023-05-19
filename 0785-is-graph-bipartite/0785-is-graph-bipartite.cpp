class Solution {
public:
    bool helper(vector<vector<int>>& graph,int i,unordered_map<int,int> &clr,int c){
        
        if(clr.count(i)&&clr[i]!=c) return 0;
        else if(clr.count(i)) return 1;
        
        bool ans=1;
        clr[i]=c;
        for(auto iter:graph[i]){
                ans&=helper(graph,iter,clr,!c);
        }
        return ans;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        bool ans=1;
        unordered_map<int,int> clr;
        for(int i=0;i<graph.size();i++){
            if(!clr.count(i))
                ans&=helper(graph,i,clr,0);
        }
        return ans;
    }
};