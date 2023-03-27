class Solution {
public:
    int dp[1001][1001];
    int helper(string&s,int i,int j){
        if(i<0||j>=s.length()) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans=0;
        if(s[i]==s[j]){
            ans+=1+helper(s,i-1,j+1);
        }
        return dp[i][j]=ans; 
    }
    int countSubstrings(string s) {
        memset(dp,-1,sizeof dp);
        int ans=0;
        for(int i=0;i<s.length();i++){
            ans+=helper(s,i,i);
            ans+=helper(s,i,i+1);
        }
        return ans;
    }
};