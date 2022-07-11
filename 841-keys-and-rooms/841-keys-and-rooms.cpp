class Solution {
public:
    
    
    int helper(vector<vector<int>>& rooms){
        unordered_map<int,int> vis;
        int ans=0;
        queue<int> que;
        que.push(0);
        vis[0]=1;
        while(que.size()){
            int size=que.size();
            while(size--){
                int tp=que.front();
                que.pop();
                
                ans++;
                for(auto ngh:rooms[tp]){
                    if(!vis.count(ngh)){
                        vis[ngh]=1;
                        que.push(ngh);
                    }
                }
                
            }
        }
        return ans;
        
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        return rooms.size()==helper(rooms);
    }
};