class Solution {
public:
    const int M=1e9+7;
    unordered_map<int,vector<int>> umap;
    
    int dp[20001][6];
    int helper(int n,int i){
        if(n==0){
            return 1;
        }
        if(dp[n][i]!=-1) return dp[n][i];
        int ans=0;
        for(auto ngh:umap[i]){
            ans=(ans+helper(n-1,ngh)%M)%M;
        }
        return dp[n][i]=ans%M;
    }
    int countVowelPermutation(int n) {
        umap[1]={2};
        umap[2]={1,3};
        umap[3]={1,2,4,5};
        umap[4]={3,5};
        umap[5]={1};
        
        
        memset(dp,-1,sizeof dp);
        int ans=0;
        for(int i=1;i<=5;i++){
            ans=(ans+helper(n-1,i)%M)%M;
        }
        return ans;
    }
};