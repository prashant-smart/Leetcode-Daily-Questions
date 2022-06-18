class Solution {
public:
    int helper(vector<vector<int>>& grid,int i,int j){
        int n=grid.size();
        int m=grid[0].size();
        grid[i][j]=-1;
        int ans=0;
        for(int idx=0;idx<n;idx++){
            if(grid[idx][j]==1)
                ans+=helper(grid,idx,j)+1;
        }
        for(int idx=0;idx<m;idx++){
            if(grid[i][idx]==1)
                ans+=helper(grid,i,idx)+1;
        }
        return ans;
    }
    
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    cout<<i<<" "<<j<<endl;
                    int val=helper(grid,i,j);
                    val=(val==0)?0:val+1;
                    cout<<val<<endl;
                    ans+=val;
                }
            }
        }
        return ans;
    }
};