class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        queue<pair<int,int>> qu;
        unordered_map<int,int> value;
        unordered_map<int,vector<int>> adjLis;
        
        
         for(int i=0;i<n;i++){
             if(i==headID) continue;
             adjLis[manager[i]].push_back(i);
         }
        
        
        int ans=0;
        unordered_set<int> vis;
        vis.insert(headID);
        qu.push({headID,0});
        
        while(qu.size()){
            int size=qu.size();
            while(size--){
                int tp=qu.front().first;
                // cout<<tp<<" ";
                int tpVal=qu.front().second;
                qu.pop();
                vis.insert(tp);
                for(auto ngh:adjLis[tp]){
                    if(!vis.count(ngh)){
                        
                        if(value.count(ngh)){
                            value[ngh]=min(value[ngh],tpVal+informTime[tp]);
                        }else value[ngh]=tpVal+informTime[tp];
                    }
                }
            }

            for(auto i:value){
                qu.push({i.first,i.second});
                ans=max(i.second,ans);
             }
             value.clear();
        }
        return ans;
    }
};