class Solution {
public:
    static bool cmp(pair<int,int> &x,pair<int,int>&y){
        return x.second>y.second;
    }
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> umap;
        for(auto i:arr) umap[i]++;
        vector<pair<int,int>> vec;
        for(auto i:umap){
            vec.push_back({i.first,i.second});
        }
        sort(begin(vec),end(vec),cmp);
        int cnt=0;
        int sum=0;
        for(auto i:vec){
            if(sum>=arr.size()/2){
                break;
            }
            sum+=i.second;
            cnt++;
        }
        return cnt;
        
    }
};