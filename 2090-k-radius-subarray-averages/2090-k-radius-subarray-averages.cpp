class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<long long int> pre(nums.size()+1,0);
        for(int i=1;i<=nums.size();i++){
            pre[i]=nums[i-1]+pre[i-1];
        }
        
        vector<int> ans(nums.size(),-1);
        
        for(int i=0;i<nums.size();i++){
            if(i-k<0||i+k>=nums.size()) continue;
            else{
                ans[i]=(pre[i]-pre[i-k]+nums[i]+pre[i+k+1]-pre[i+1])/(2*k+1);
            }
        }
        return ans;
    }
};