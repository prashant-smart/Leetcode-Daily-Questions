class Solution {
public:
    int dp[101][101];
    
    int ngh[3][2]={{1,-1},{1,0},{1,1}};
    
    long long helper(vector<vector<int>>& matrix,int i,int j){
        if(i==matrix.size()) return 0;
        
        if(i<0||j<0||j>=matrix[0].size()) return INT_MAX;
        
        if(dp[i][j]!=-1) return dp[i][j];
        long long ans=INT_MAX;
        
        for(auto dic:ngh){
            ans=min(ans,matrix[i][j]+helper(matrix,i+dic[0],j+dic[1]));
        }
        return dp[i][j]=ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        memset(dp,-1,sizeof dp);
        
        long long ans=INT_MAX;
        
        for(int j=0;j<matrix[0].size();j++){
            ans=min(helper(matrix,0,j),ans);
        }
        
        return ans;
        
    }
};