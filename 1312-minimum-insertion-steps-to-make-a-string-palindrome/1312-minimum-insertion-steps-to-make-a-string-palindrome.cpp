class Solution {
public:
    int dp[501][501];
    int helper(string &s,int i,int j){
         if(i>=j) return 0;
         
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        if(s[i]==s[j]){
            ans=min(helper(s,i+1,j-1),ans);
        }
        ans=min({ans,1+helper(s,i+1,j),1+helper(s,i,j-1)});
        return dp[i][j]=ans;
    }
    int minInsertions(string s) {
        memset(dp,-1,sizeof dp);
        return helper(s,0,s.length()-1);   
    }
};