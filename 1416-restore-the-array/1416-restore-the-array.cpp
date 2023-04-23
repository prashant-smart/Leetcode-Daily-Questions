class Solution {
public:
    long long dp[100000+1];
    const int md=1e9+7;
    int helper(string &s,int &k,int i){
        if(i>=s.length()) return 1;
        // cout<<i<<" ";
        if(dp[i]!=-1) return dp[i]%md;
        long long num=0;
        long long sum=0;
        for(int j=i;j<s.length();j++){
            num=num*10+s[j]-'0';
            if(num<=0) break;
            if(num<=k){
                sum=(sum+helper(s,k,j+1))%md;
            }else break;
        }
        
        return dp[i]=sum%md;
        
    }
    int numberOfArrays(string s, int k) {
        memset(dp,-1,sizeof dp);
        return helper(s,k,0);
    }
};