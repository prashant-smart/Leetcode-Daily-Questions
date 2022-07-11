class Solution {
public:
    set<pair<int,int> >vis;
    void helper(unordered_map<int,vector<int> > &umapx,unordered_map<int,vector<int> > &umapy,int x,int y){
        vis.insert({x,y});
        for(auto Y:umapx[x]){
            if(!vis.count({x,Y})){
                helper(umapx,umapy,x,Y);
            }
        }
        
        for(auto X:umapy[y]){
            if(!vis.count({X,y})){
                helper(umapx,umapy,X,y);
            }
        }
        
    }
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int,vector<int> > umapx,umapy;
        for(auto i:stones){
            umapx[i[0]].push_back(i[1]);
            umapy[i[1]].push_back(i[0]);
        }
        
        
   
        
        int ans=0;
        for(auto pr:umapx){
            for(auto y:pr.second){
                if(!vis.count({pr.first,y})){
                    ans++;
                    helper(umapx,umapy,pr.first,y);
                }
            }
        }
        return stones.size()-ans;
    }
};