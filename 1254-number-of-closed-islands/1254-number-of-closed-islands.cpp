class Solution {
public:
    bool check(vector<vector<int>>& grid,int i, int j){
        if(i<0||j<0||j>=grid[0].size()||i>=grid.size()) return 0;
        return 1;
    }
    int directions[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
    
    bool findValidIsland(vector<vector<int>>& grid,int i,int j){
        if(!check(grid,i,j)) return 0;
        if(grid[i][j]==1||grid[i][j]==-1) return 1;
        grid[i][j]=-1;
        
        bool isValidIsland=1;
        
        for(auto sides:directions){
            
                isValidIsland&=findValidIsland(grid,i+sides[0],j+sides[1]);
        }
        return isValidIsland;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int ans=0;
        
        for(int row=0;row<grid.size();row++){
            for(int col=0;col<grid[0].size();col++){
                if(grid[row][col]==0){
                    if(findValidIsland(grid,row,col)){
                        ans++;
                    }
                }
            }
        }
        return ans;
        
    }
};