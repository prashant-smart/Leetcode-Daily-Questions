class Solution {
public:
    queue<vector<int>> que;
    vector<vector<int>> direc={{-1,0},{0,-1},{1,0},{0,1}};
    void helper(vector<vector<int>>& mat,vector<vector<int>>& dp){
        while(que.size()){
            int sz=que.size();
            while(sz--){
                auto tp=que.front();
                que.pop();
                if(mat[tp[0]][tp[1]]==1)
                    dp[tp[0]][tp[1]]=min(dp[tp[0]][tp[1]],tp[2]);
                mat[tp[0]][tp[1]]=2;
                
                for(auto ngh:direc){
                    int ii=tp[0]+ngh[0];
                    int jj=tp[1]+ngh[1];
                    if(ii>=0&&ii<mat.size()&&jj>=0&&jj<mat[0].size()&&mat[ii][jj]!=2){
                        que.push({ii,jj,tp[2]+1});
                    }
                }
            }
        }
        
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> dp(mat.size(),vector<int>(mat[0].size(),INT_MAX));
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0) que.push({i,j,0});
            }
        }
        
        helper(mat,dp);
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(dp[i][j]==INT_MAX) dp[i][j]=0;
            }
        }
        return dp;
        
    }
};