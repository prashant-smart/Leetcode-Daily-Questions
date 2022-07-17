class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int> umap;
        for(auto i:nums){
            umap[i]++;
        }
        int first=0,sec=0;
        for(auto i:umap){
            if(i.second==0) continue;
            if(i.second%2==0){
                first+=i.second/2;
            }else{
                first+=i.second/2;
                sec+=i.second%2;
            }
        }
        return {first,sec};
    }
};