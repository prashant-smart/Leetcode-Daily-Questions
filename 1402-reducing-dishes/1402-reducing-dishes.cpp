class Solution {
public:
    int dp[505][505];
    int helper(vector<int>&vec,int i,int tm){
        if(i>=vec.size()) return 0;
        if(dp[i][tm]!=-1) return dp[i][tm];
        return dp[i][tm]=max({vec[i]*tm+helper(vec,i+1,tm+1),helper(vec,i+1,tm)});
    }
    int maxSatisfaction(vector<int>& vec) {
        memset(dp,-1,sizeof dp);
        sort(begin(vec),end(vec));
        return helper(vec,0,1);
    }
};