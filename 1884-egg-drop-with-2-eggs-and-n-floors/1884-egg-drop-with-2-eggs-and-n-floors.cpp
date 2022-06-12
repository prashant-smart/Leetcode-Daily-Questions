class Solution {
public:
    int res = 1e9;
    int dp[1001][3];
    int solve(int n , int eggs)
    {
        // base case
        // if no.of floors left is 1 or 0 we need to take n moves
        if(n<=1)
         return n;
        // suppose 1st egg broke at mth floor then we need to take atleat m-1 try ' s
        if(eggs == 1)
            return n;
        
        if(dp[n][eggs]!=-1)
            return dp[n][eggs];
        
        int ans = 1e8;
        //at the ith floor either the eg will break or survive 
        // 1. if it break at ith floor we need to try for i-1 foors in worst case
        // 2. 1st do not break at i th then we need to search for n-i left floors
        for(int  i = 1 ; i < n ;i++)
        {
            ans = min(ans , max(solve(i-1,eggs-1) , solve(n-i , eggs)) + 1);
        }
        return dp[n][eggs] = ans;
    }
    int twoEggDrop(int n) {
        if(n <= 1)
            return n;
        int eggs = 2 ;
        memset(dp,-1,sizeof(dp));
        return solve(n,eggs);
    }
};