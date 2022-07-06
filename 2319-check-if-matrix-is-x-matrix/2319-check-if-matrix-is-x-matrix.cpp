class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        for(int i=0;i<grid[0].size();i++){
                if(grid[i][i]==0||grid[i][grid.size()-1-i]==0) return 0;
                grid[i][i]=0;
                grid[i][grid.size()-1-i]=0;
        }
        
        for(int i=0;i<grid.size();i++){
                for(int j=0;j<grid[0].size();j++){
                    if(grid[i][j]!=0) return 0; 
                    // cout<<grid[i][j]<<" ";
                }
            // cout<<endl;
        }
        return 1;
        
    }
};