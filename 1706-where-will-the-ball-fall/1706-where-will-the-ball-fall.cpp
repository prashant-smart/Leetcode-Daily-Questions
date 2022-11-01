class Solution {
public:
    
    int helper(vector<vector<int>>& grid,int prev,int i,int j,int isup){
       
        if(i<0||j<0||j>=grid[0].size()) return -1;
        if(i>=grid.size()) return j;
        
        int curr=grid[i][j];
        // cout<<i<<" "<<j<<" "<<prev<<" "<<curr<<endl;
        if(prev==1&&curr==-1&&!isup||prev==-1&&curr==1&&!isup) return -1;
          
        if(grid[i][j]==1){
            if(isup)  return helper(grid,curr,i,j+1,!isup);
            else return helper(grid,curr,i+1,j,!isup);
        }
        else{
            if(isup){
                  return helper(grid,curr,i,j-1,!isup) ;
            }else return helper(grid,curr,i+1,j,!isup);
        }
    
        return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans(grid[0].size(),-1);
        for(int i=0;i<grid[0].size();i++){
            int k=helper(grid,0,0,i,1);
            if(k!=-1){
                ans[i]=k;
            }
        }
        
             
        return ans;
    }
};