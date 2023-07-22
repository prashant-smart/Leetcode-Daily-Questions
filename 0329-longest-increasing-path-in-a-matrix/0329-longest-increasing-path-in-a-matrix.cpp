class Solution {
public:
    int dp[201][201];
    bool check(vector<vector<int>>& vec,int i,int j){
        if(i<0||j<0||i>=vec.size()||j>=vec[0].size()){
            return 0;
        }
        return 1;
    }
    vector<vector<int>> direc={{1,0},{0,1},{-1,0},{0,-1}};
    int helper(vector<vector<int>>& vec,int i,int j){
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=1;
        for(auto d:direc){
            int ii=i+d[0];
            int jj=j+d[1];
            if(check(vec,ii,jj)&&vec[ii][jj]>vec[i][j]){
                ans=max(ans,1+helper(vec,ii,jj));
            }
        }
        return dp[i][j]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& vec) {
        memset(dp,-1,sizeof dp);
        int ans=0;
        for(int i=0;i<vec.size();i++){
            for(int j=0;j<vec[0].size();j++){
                ans=max(ans,helper(vec,i,j));
            }
        }
        // for(int i=0;i<vec.size();i++){
        //     for(int j=0;j<vec[0].size();j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return ans;
    }
     
};