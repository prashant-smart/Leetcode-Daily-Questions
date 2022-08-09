class Solution {
public:
    const int MOD=1e9+7;
    int dp[1001];
    int helper(unordered_map<int,int>&umap,vector<int>& arr,int p){
        
        int f = 0;
        int parent = arr[p];
        for(auto i : umap){
            if(parent%i.first == 0 && umap.find(parent/i.first) != umap.end()){
                f = 1;
                break;
            }
        }
        if(f == 0){
            return 1;
        }
        if(dp[p] != -1)return dp[p];
        
        long long ans = 0;
        for(auto i : umap){
            if(parent%i.first == 0 && umap.find(parent/i.first) != umap.end()){
                long long a = helper(umap, arr, umap[i.first])%MOD;
                long long b = helper(umap, arr, umap[parent/i.first])%MOD;
                ans =(ans %MOD + (a  * b)%MOD)%MOD;
            }
        }
        return dp[p] = (ans + 1)%MOD;
    }
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int,int>umap;
        memset(dp,-1,sizeof dp);
        for(int i=0;i<arr.size();i++) umap[arr[i]]=i;
        
        int ans = 0;
        for(int i = 0; i < arr.size();i++){
            ans = ((ans%MOD) + helper(umap, arr, i)%MOD)%MOD;
        }
        return ans%MOD;
    }
};