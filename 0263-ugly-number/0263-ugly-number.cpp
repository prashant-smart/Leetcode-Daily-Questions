class Solution {
public:
    int dp[10000];
    bool helper(int n) {
       if(n<=0) return 0;
        else if(n==1||n==2||n==3||n==5) return 1;
        // if(dp[n]!=-1) return dp[n];
        bool isvalid=0;
        if(n%2==0){
            isvalid|=helper(n/2);
        }
        if(n%3==0){
            isvalid|=helper(n/3);
        }
        if(n%5==0){
            isvalid|=helper(n/5);
        }
        return isvalid;
    }
    bool isUgly(int n){
        memset(dp,-1,sizeof dp);
        return helper(n);
    }

};