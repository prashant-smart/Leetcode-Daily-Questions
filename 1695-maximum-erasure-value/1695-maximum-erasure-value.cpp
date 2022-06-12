class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<int> pre(nums.size()+1,0);
        for(int i=0;i<nums.size();i++){
            pre[i+1]=nums[i]+pre[i];
        }
        
        int i=0,j=0;
        int ans=0;
        unordered_map<int,int> umap;
        while(j<nums.size()){
            if(i==j){
                ans=max(ans,nums[i]);
                umap[nums[j]]=j;
                j++;
            }else if(umap.count(nums[j])){
                if(umap[nums[j]]>=i){
                    i=umap[nums[j]]+1;
                } 
                umap[nums[j]]=j;
                ans=max(ans,pre[j+1]-pre[i]);
                j++;
            }else{
                umap[nums[j]]=j;
                ans=max(ans,pre[j+1]-pre[i]);
                j++;
            }
            
        }
        return ans;
    }
};