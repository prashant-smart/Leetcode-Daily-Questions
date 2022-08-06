class Solution {
public:
    int dp[1001];
    
    int helper(vector<int>& nums, int &target,int sum){
        if(sum==target) return 1;
        if(sum>target) return 0;
        if(dp[sum]!=-1) return dp[sum];
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=helper(nums,target,sum+nums[i]);
        }
        return dp[sum]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof dp);
        
        return helper(nums,target,0);
    }
};