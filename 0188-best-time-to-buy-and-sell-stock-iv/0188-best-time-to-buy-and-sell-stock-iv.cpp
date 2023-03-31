class Solution {
public:
    int dp[1001][101];
    int helper(vector<int>&vec,int k,int i){
        if(!k || i>=vec.size()) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int ans=0;
        for(int ii=i+1;ii<vec.size();ii++){
            ans=max(ans,(vec[ii]-vec[i])+helper(vec,k-1,ii+1));
        }
        ans=max(ans,helper(vec,k,i+1));
        return dp[i][k]=ans;
        
    }
    int maxProfit(int k, vector<int>& vec) {
        memset(dp,-1,sizeof dp);
        return helper(vec,k,0);
    }
};