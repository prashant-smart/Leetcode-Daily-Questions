class Solution {
public:
    int dp[1001][1001];
    int helper(string &s1,string &s2,int i,int j){
        if(i==s1.length()&&j==s2.length()){
            return 0;
        }
        if(i>s1.length()||j>s2.length()){
            return INT_MAX/4;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans=INT_MAX;
        if(s1[i]==s2[j]){
            ans=min(ans,helper(s1,s2,i+1,j+1));
        }else{
            ans=min({ans,s2[j]+helper(s1,s2,i,j+1),s1[i]+helper(s1,s2,i+1,j)});
        }
        return dp[i][j]=ans;
    }
    int minimumDeleteSum(string s1, string s2) {
        memset(dp,-1,sizeof dp);
        return helper(s1,s2,0,0);
    }
};