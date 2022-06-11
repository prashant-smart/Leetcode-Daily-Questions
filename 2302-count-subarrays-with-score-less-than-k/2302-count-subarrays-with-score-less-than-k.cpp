class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        vector<long long> pre(nums.size()+1,0);
        for(int i=0;i<nums.size();i++){
            pre[i+1]=nums[i]+pre[i];
        }
        
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            int low=i,high=nums.size()-1;
            while(high-low>1){
                int mid=low+(high-low)/2;
                if((pre[mid+1]-pre[i])*(mid-i+1)>=k){
                    high=mid-1;
                }else low=mid;
            }
            
            if((pre[high+1]-pre[i])*(high-i+1)<k){
                ans+=(high-i+1);
                    
            }else if((pre[low+1]-pre[i])*(low-i+1)<k){
                ans+=(low-i+1);
            }
        }
        return ans;
    }
};