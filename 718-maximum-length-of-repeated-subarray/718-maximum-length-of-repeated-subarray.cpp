class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=max(nums1.size(),nums2.size());
        int dp[n+1][n+1];
        memset(dp,-1,sizeof(dp));
        int mx=0;
        
        for(int i=0;i<=n;i++){
            dp[i][0]=dp[0][i]=0;
        }
            for(int i=1;i<=nums1.size();i++){
                for(int j=1;j<=nums2.size();j++){
                    if(nums1[i-1]==nums2[j-1]){
                        dp[i][j]=1+dp[i-1][j-1];
                        mx=max(dp[i][j],mx);
                    }else dp[i][j]=0;
                }
            }
        
        return mx;
    }
};