class Solution {
public:
    
    vector<int> maxSubsequence(vector<int>& nums, int k) {
       int sum=0;
        vector<int> n=nums;
        sort(begin(n),end(n));
        unordered_map<int,int> umap;
        int kp=nums.size()-k;
        int i=0;
        while(kp--){
            umap[n[i++]]++;
        }
        
        for(auto i:nums) sum+=i;
        
        vector<int> ans;
        for(auto i:nums){
            if(!umap[i]){
                ans.push_back(i);
            }else umap[i]--;
        }
        return ans;
        
    }
};