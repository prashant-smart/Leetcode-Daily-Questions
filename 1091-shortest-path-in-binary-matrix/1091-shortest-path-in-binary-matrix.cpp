class Solution {
public:
    bool isvalid(vector<vector<int>>& grid,int i,int j){
        int n=grid.size();
        int m=grid[0].size();
        if(i>=0&&i<n&&j>=0&&j<m&&grid[i][j]==0) return 1;
        return 0;
    }
    vector<vector<int>> direc={{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{-1,1},{1,1},{1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int arr[grid.size()][grid[0].size()];
        memset(arr,0,sizeof arr);
        queue<pair<int,int> > que;
        if(grid[0][0] ==1) return -1;
        
        que.push({0,0});
        int len=0;
        while(que.size()){
            int sz=que.size();
            while(sz--){
                auto tp=que.front();
                que.pop();
                if(tp.first==grid.size()-1&&tp.second==grid[0].size()-1) return len+1;
                for(auto ngh:direc){
                    int i=tp.first+ngh[0];
                    int j=tp.second+ngh[1];
                    if(isvalid(grid,i,j)&&arr[i][j]!=1){
                        arr[i][j]=1;
                        que.push({i,j});
                    }
                }
            }
            len++;
        }
        return -1;
        
    }
};