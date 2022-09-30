class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& b) {
        vector<vector<int>> vec;
        for(auto i:b){
            vec.push_back({i[0],-1*i[2]});
            vec.push_back({i[1],i[2]});
        }
        sort(vec.begin(),vec.end());
        priority_queue<int> pq;
        pq.push(0);
        vector<vector<int>> ans;
        unordered_map<int,int> umap;
        umap[0]=1;
        for(auto i:vec){
            if(i[1]<0 ){
                
                if(abs(i[1])>pq.top())
                    ans.push_back({i[0],abs(i[1])});
                umap[abs(i[1])]++;
                pq.push(abs(i[1]));
            }else if(i[1]>0){
               
                umap[i[1]]--;
                while(umap[pq.top()]==0){
                    pq.pop();
                }
                if(pq.top()<i[1])
                    ans.push_back({i[0],pq.top()});
            }
        }
        return ans;
    }
};