class Solution {
public:
    int ans = 0;
    int solve(int target, vector<int>&nums, vector<int>&dp){
        //base
        if(target==0) {
            return 1;
        }
        if(target<0) return 0;
        
        //check if already we calculated
        if(dp[target] != -1) return dp[target];
        
        //hypo
        int temp = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<=target) temp += solve(target-nums[i], nums, dp);
        }
        return dp[target] = temp;
    }
    int combinationSum4(vector<int>& nums, int target) {
        if(target == 0) return 0;
        vector<int>dp(target+1, -1);
        return solve(target, nums, dp);
    }
};