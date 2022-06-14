class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1&&trust.size()==0) return 1;
        unordered_map<int,int> umap;
        
        for(auto i:trust){
            umap[i[1]]++;
        }
        int judge=-1;
        for(auto i:umap){
            if(i.second==n-1){
                judge=i.first;
                break;
            }
        }
        for(auto i:trust){
            if(i[0]==judge)
                return -1;
        }
        return judge;
    }
};