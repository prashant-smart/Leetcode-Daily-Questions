class Solution {
public:
    int dp[105][105];
    int helper(int &n,vector<int>&vec,int i,int j){
        if(i>=j||i+1==j||i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int ii=i+1;ii<j;ii++){
            ans=min(ans,helper(n,vec,i,ii)+helper(n,vec,ii,j)+vec[j]-vec[i]);
        }
        return dp[i][j]=(ans==INT_MAX?0:ans);
    }
    int minCost(int n, vector<int>& vec) {
        vector<int>v;
        sort(begin(vec),end(vec));
        v.push_back(0);
        for(auto i:vec){
            v.push_back(i);
        }
        v.push_back(n);
        memset(dp,-1,sizeof dp);
        return helper(n,v,0,v.size()-1);
    }
};