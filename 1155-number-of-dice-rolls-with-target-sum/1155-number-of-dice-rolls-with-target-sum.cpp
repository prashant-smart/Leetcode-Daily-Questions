class Solution {
public:
    int mod = 1e9 + 7;   // taking mod as it is clearly mentioned that size is going to be large
    long solve(int i, int k , int target, int sum,vector<vector<int>> &dp){
        //if i reach 0 i.e.,summed all my die values if sum equals to target i return the recursion as
        //success hence 1. else 0.
        if(i<1 && sum==target){
            return 1;
        }
        if(i<1) return 0;
        if(dp[i][sum]!=-1) return dp[i][sum]; // this is nothing but memoization of our recursion
        long temp =0;
        for(int j=1; j<=k; j++){
            temp += solve(i-1,k,target,sum+j,dp);
        }
        return dp[i][sum]= temp%mod; //whatever is the answer of this combination we store it for             //future use
    }
    
    int numRollsToTarget(int n, int k, int target) {
        //create a 2D vector to store the results of previous combinations.
        vector<vector<int>> dp(n+1,vector<int>(1001,-1));
        return solve(n,k,target,0,dp);
    }
};