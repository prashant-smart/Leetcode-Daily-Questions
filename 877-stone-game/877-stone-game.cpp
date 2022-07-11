class Solution {
public:
    int dp[505][505];
    bool helper(vector<int>& piles,int i,int j,int &sum,int Alice){
        if(i>=j) return Alice>(sum-Alice);
        if(dp[i][j]==-1) return dp[i][j];
        return dp[i][j]=helper(piles,i+1,j,sum,Alice+piles[i])||helper(piles,i,j-1,sum,Alice+piles[j]);
    }
    bool stoneGame(vector<int>& piles) {
        int sum=0;
        for(auto i:piles){
            sum+=i;
        }
        memset(dp,-1,sizeof dp);
        return helper(piles,0,piles.size()-1,sum,0);
    }
};