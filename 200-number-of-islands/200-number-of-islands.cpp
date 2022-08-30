class Solution {
public:
    int sides[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
    queue<pair<int,int>> neighbourNode;
    bool check(vector<vector<char>>& grid,int row,int col){
        if(row<0||col<0||row>=grid.size()||col>=grid[0].size()) return 0;
        return 1;
    }
    int markIsland(vector<vector<char>>& grid,int row,int col){
        neighbourNode.push({row,col});
        grid[row][col]='2';
        while(neighbourNode.size()){
            int size=neighbourNode.size();
            while(size--){
                row=neighbourNode.front().first;
                col=neighbourNode.front().second;
                neighbourNode.pop();
                for(auto side:sides){
                    if(check(grid,row+side[0],col+side[1])&&grid[row+side[0]][col+side[1]]=='1'){
                        neighbourNode.push({row+side[0],col+side[1]});
                        grid[row+side[0]][col+side[1]]='2';
                    }
                }
            }
        }
        return 1;
    }
    int numIslands(vector<vector<char>>& grid) {
        int numberOfIslands=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    numberOfIslands+=markIsland(grid,i,j);
                }
            }
        }
        return numberOfIslands;
    }
};