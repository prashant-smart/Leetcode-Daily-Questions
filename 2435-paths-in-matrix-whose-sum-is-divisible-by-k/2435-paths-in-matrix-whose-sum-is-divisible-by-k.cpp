class Solution {
public:
    const int m=1000000000+7;
    unordered_map<string,long long> umap;
    int helper(vector<vector<int>>& grid,int i,int j,int sum ,int &k,vector<vector<vector<int>>>& dp){
        sum%=k;
        if(i>=grid.size()||i<0||j>=grid[0].size()||j<0) return 0;
        if(i==grid.size()-1&&j==grid[0].size()-1&&(sum+grid[i][j])%k==0){
            
            return 1;
        } 
        if(dp[i][j][sum]!=-1) return dp[i][j][sum];
        
        
        return dp[i][j][sum]=(helper(grid,i+1,j,sum+grid[i][j],k,dp)%m+helper(grid,i,j+1,sum+grid[i][j],k,dp)%m)%m;
        
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        vector<vector<vector<int>>> dp(grid.size()+1,vector<vector<int>>(grid[0].size()+1,vector<int>(k+1,-1)));
        return helper(grid,0,0,0,k,dp);
    }
};