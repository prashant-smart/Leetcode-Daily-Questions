class Solution {
public:
    int dp[1001][2001];
    int helper(vector<vector<int>>& piles,int i,int k){
        if(k==0||i>=piles.size()) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int val1=helper(piles,i+1,k);
        int sum=0;
        int ans=0;
        
        for(int j=0;j<min((int)piles[i].size(),k);j++){
                sum+=piles[i][j];
                ans=max(ans,sum+helper(piles,i+1,k-(j+1)));
        }
        return dp[i][k]=max(ans,val1);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp,-1,sizeof(dp));
        return helper(piles,0,k);
    }
};