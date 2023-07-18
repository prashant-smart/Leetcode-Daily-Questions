class Solution {
public:
    unordered_map<int,int> inodr;
    unordered_map<int,vector<int>> adj;
    vector<int>ans;
    void helper(int num){
        ans.push_back(num);
        inodr[num]--;
        for(auto iter:adj[num]){
            inodr[iter]--;
            if(inodr[iter]==0){
                helper(iter);
            }
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& p) {
        for(auto iter:p){
            adj[iter[1]].push_back(iter[0]);
            inodr[iter[0]]++;
        }
        for(int iter=0;iter<numCourses;iter++){
            if(inodr[iter]==0){
                helper(iter);
            }
        }
        
        if (ans.size()==numCourses)return ans;
        return {};
    }
};