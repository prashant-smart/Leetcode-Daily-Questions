class Solution {
public:
    
    bool check(vector<int>& nums){
        for(auto i:nums){
            if(i!=0) return 0;
        }
        return 1;
    }
    int find(vector<int>& nums){
        int mn=INT_MAX;
         for(auto i:nums){
             if(i<mn&&i!=0){
                 mn=i;
             }
         }
        
        for(auto &i:nums){
            if(i>0){
                i-=mn;
            }
        }
        return 1;
    }
    int minimumOperations(vector<int>& nums) {
        int ans=0;
        
        while(!check(nums)){
            ans+=find(nums);
        }
        return ans;
    }
};