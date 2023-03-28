class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for(auto i:nums){
            auto it=lower_bound(begin(dp),end(dp),i)-begin(dp);
            // cout<<it<<" ";
            
            if(it+begin(dp)==end(dp)){
                dp.push_back(i);
            }
            else{
                dp[it]=min(dp[it],i);
            }
        }
        return dp.size();
    }
};