//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
 set<vector<pair<int,int>>> st;
  vector<vector<int>> direc={{1,0},{0,1},{-1,0},{0,-1}};
//   int bfs(vector<vector<int>>& grid,queue<vector<int>> que){
//       int ans=0;
//       while(que.size()){
//           bool isvalid=0;
//           int sz=que.size();
//           while(sz--){
//               auto tp=que.front();
//               que.pop();
              
//               grid[tp[0]][tp[1]]=-1;
//               strength[tp[2]]--;
//               for(auto ngh:direc){
//                 int i=tp[0]+ngh[0];
//                 int j=tp[1]+ngh[1];
//                 if(i>=0&&i<grid.size()&&j>=0&&j<grid[0].size()&&grid[i][j]==tp[2]){
//                   grid[i][j]=-1;
//                   que.push({i,j,tp[2]});
//                 }
                
//               }
//               if(strength[tp[2]]==0) isvalid=1;
//           }
//           if(isvalid) ans++;
//       }
//       return ans;
//   }
    int dfs(vector<vector<int>>& grid,int i,int j,int &clr,int &bi,int &bj,vector<pair<int,int>> &v){
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]!=1) return 0;
        grid[i][j]=clr;
        v.push_back({i-bi,j-bj});
        int ans=1;
        for(auto ngh:direc){
            int ii=i+ngh[0];
            int jj=j+ngh[1];
            ans+=dfs(grid,ii,jj,clr,bi,bj,v);
        }
        return ans;
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int clr=2;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    vector<pair<int,int>> v;
                    dfs(grid,i,j,clr,i,j,v);
                    clr++;
                    st.insert(v);
                }
            }
        }
        
        // unordered_set<int> clrs={0};
        
        // unordered_map<int,queue<vector<int>>> umap;
        // for(int i=0;i<grid.size();i++){
        //     for(int j=0;j<grid[0].size();j++){
        //         if(!clrs.count(grid[i][j])){
        //             umap[strength[grid[i][j]]].push({i,j,grid[i][j]});
        //             clrs.insert(grid[i][j]);
        //         }
        //     }
        // }
        // int ans=0;
        // for(auto i:umap){
        //     ans+=bfs(grid,i.second);
        // }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends