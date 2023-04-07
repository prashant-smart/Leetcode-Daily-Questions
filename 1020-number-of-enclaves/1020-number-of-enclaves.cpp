class Solution {
public:
    bool isvalid(vector<vector<int>>& grid,int i,int j){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]==-1||grid[i][j]==0) return 0;
        return 1;
    }
    vector<vector<int>> direc={{0,1},{1,0},{-1,0},{0,-1}};
    void helper(vector<vector<int>>& grid,int i,int j){
        if(!isvalid(grid,i,j)) return ;
        
        grid[i][j]=-1;
        for(auto ii:direc){
            helper(grid,i+ii[0],j+ii[1]);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(i==0||j==0||j==grid[0].size()-1||i==grid.size()-1){
                    helper(grid,i,j);
                }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};