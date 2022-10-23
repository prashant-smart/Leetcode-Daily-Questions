class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> umap;
        for(auto i:nums) umap[i]++;
        int a,b;
        for(int i=1;i<=nums.size();i++){
            if(!umap.count(i)) b=i;
            else if(umap[i]==2) a=i;
        }
        return {a,b};
    }
};