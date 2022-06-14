class Solution {
public:
    int dp[502][502];
    int helper(int i,int j,string& word1, string& word2){
        if(i<0||j<0||i>=word1.length()||j>=word2.length()) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        // cout<<i<<","<<j<<" ";
        if(word1[i]==word2[j]) return 1+helper(i+1,j+1,word1,word2);
        
        return dp[i][j]=max(helper(i,j+1,word1,word2),helper(i+1,j,word1,word2)); 
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return (word1.length()+word2.length()-2*helper(0,0,word1,word2));
    }
};