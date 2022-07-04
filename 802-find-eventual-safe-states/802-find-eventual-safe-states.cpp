class Solution {
public:
    vector<int> ans;
    unordered_set<int> terminalNode;
    unordered_map<int,int> visitedNode;
    
    
    
    bool helper(unordered_map<int,vector<int>> &adjLis,int currNode,unordered_set<int>&visited){
        if(terminalNode.count(currNode)){
            return 1;
        }
        
        if(visitedNode.count(currNode)){
            return visitedNode[currNode];
        }
        
        int isvalidPath=0;
        visited.insert(currNode);
        int numberOfNgh=0;
        
        for(auto ngh:adjLis[currNode]){
            numberOfNgh++;
            if(!visited.count(ngh)){
                
                isvalidPath+=helper(adjLis,ngh,visited);
            }else{
                if(visitedNode[ngh]){
                    isvalidPath++;
                }else return visitedNode[currNode]=0;
            }
        }
        visitedNode[currNode]=(isvalidPath==numberOfNgh&&numberOfNgh);
        return (isvalidPath==numberOfNgh&&numberOfNgh);
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int,vector<int>> adjLis;
        
        for(int i=0;i<graph.size();i++){
            if(!graph[i].size()){
                terminalNode.insert(i);
                ans.push_back(i);
            }
            for(auto ngh:graph[i]){
                adjLis[i].push_back(ngh);
            }
        
        }
        unordered_set<int>visited;
        for(auto node:adjLis){
            
            if(helper(adjLis,node.first,visited)){
                ans.push_back(node.first);
            }
            
        }
        sort(begin(ans),end(ans));
        return ans;
    }
};