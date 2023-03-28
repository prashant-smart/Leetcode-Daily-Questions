class Solution {
public:
    long mod=pow(10, 9) + 7;
    long dp[5000+1][4][3];
    int helper(int currlen,int i,int j){
        if(i < 0 || j < 0 || i >= 4 || j >= 3 || (i == 3 && j != 1)) return 0;
        if(currlen==1)
            return 1;
        if(dp[currlen][i][j]!=-1)
            return dp[currlen][i][j];
        long upper=(helper(currlen-1,i-2,j+1)%mod+helper(currlen-1,i-2,j-1)%mod);
        long lower=(helper(currlen-1,i+2,j+1)%mod+helper(currlen-1,i+2,j-1)%mod);
        long right=(helper(currlen-1,i+1,j+2)%mod+helper(currlen-1,i-1,j+2)%mod);
        long left=(helper(currlen-1,i+1,j-2)%mod+helper(currlen-1,i-1,j-2)%mod);
        
        return dp[currlen][i][j]=(upper+left+lower+right)%mod;
    }
    int knightDialer(int n) {
        long ans=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                ans=(helper(n,i,j)+ans)%mod;
            }
        }
        return ans;
        
    }
};