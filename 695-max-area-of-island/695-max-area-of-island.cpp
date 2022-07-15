class Solution {
public:
    
    int helper(vector<vector<int>>& vec,int i,int j){
        if(i<0 ||i>=vec.size()||j<0||j>=vec[0].size()|| vec[i][j]==0){
            return 0;
        }
        vec[i][j]=0;
        return 1+helper(vec,i,j+1)+
                helper(vec,i,j-1)+
                helper(vec,i+1,j)+
                helper(vec,i-1,j);
        
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count=0;
       for(int i=0;i<grid.size();i++){
           for(int j=0;j<grid[0].size();j++){
                count=max(helper(grid,i,j),count);
           }
       } 
        return count;
    }
};