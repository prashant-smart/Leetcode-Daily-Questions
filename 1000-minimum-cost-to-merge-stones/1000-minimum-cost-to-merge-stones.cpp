class Solution {
public:
    int dp[50][50][50];
    int helper(vector<int>& stones,vector<int> &pre, int i,int j,int piles,int k){
        if(i==j&&piles==1) return 0;
        if(i==j) return INT_MAX/4;
        
        if(dp[i][j][piles]!=-1) return dp[i][j][piles];
        if(piles==1){
            return dp[i][j][piles]=helper(stones,pre,i,j,k,k)+((i!=0)? pre[j]-pre[i-1]:pre[j]);
        }
        int ans=INT_MAX/4;
        for(int ii=i;ii<j;ii++){
            ans=min(ans,helper(stones,pre,i,ii,1,k)+helper(stones,pre,ii+1,j,piles-1,k));
        }
        return dp[i][j][piles]=ans;
    }
    int mergeStones(vector<int>& stones, int k) {
        if((stones.size()-1)%(k-1)!=0)
            return -1;
         int sum = 0;
        vector<int>pre;
        for(int i=0;i<stones.size();i++){
            sum+=stones[i];
            pre.push_back(sum);
        }
        memset(dp,-1,sizeof(dp));
        return helper(stones,pre,0,stones.size()-1,1,k);
        
    }
};