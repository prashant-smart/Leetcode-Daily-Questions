class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int,int> umap;
        int ans=INT_MAX;
        vector<int> left(nums.size(),0),right(nums.size()-1,0);
        for(int i=0;i<nums.size();i++){
            if(i==0) left[i]=nums[i];
            else left[i]=nums[i]+left[i-1];
            if(left[i]==x) ans=min(ans,i+1);
            
        }
        
        for(int i=0;i<left.size();i++) umap[left[i]]=i;
        
        
        
        for(int i=nums.size()-1;i>=0;i--){
            x-=nums[i];
            cout<<x<<" ";
            if(x!=0&&umap.count(x)&&umap[x]<i){
                ans=min(ans,(int)nums.size()-i+umap[x]+1);
            }
            else if(x==0){ ans=min(ans,(int)nums.size()-i);}
            
        }
        return (ans!=INT_MAX)?ans:-1;
    }
};