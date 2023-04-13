class Solution {
public:
    class DSU{
        public:
        vector<int> parent;
        vector<int> size;
        int N;
        DSU(int n){
            parent.resize(n*n+n);
            N=n;
            size.resize(n*n+n);
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    parent[i*n+j]=i*n+j;
                    size[i*n+j]=1;
                }
            }
        }
        
        int find(int i,int j){
            // cout<<i<< " "<<j<<endl;
            if(parent[i*N+j]==i*N+j) return i*N+j;
            int par=parent[i*N+j];
            int pi=par/N;
            int pj=par%N;
            return parent[i*N+j]=find(pi,pj);
        }
        
        void unite(int i1,int j1,int i2,int j2){
            int p1=find(i1,j1);
            int p2=find(i2,j2);
            if(size[p2]>size[p1]){
                parent[p1]=p2;
                size[p2]+=size[p1];
            }else{
                parent[p2]=p1;
                size[p1]+=size[p2];
            }
            
        }
        
    };
    bool check(vector<vector<int>>& grid,int i,int j){
        int n=grid.size();
        
        if(i<0||j<0||i>=n||j>=n||grid[i][j]==0) return 0;
        return 1;
    }
    vector<vector<int>> direc={{1,0},{0,1},{-1,0},{0,-1}};
    int findStrength(vector<vector<int>>& grid,int i,int j,DSU& d){
        unordered_map<int,int> umap;
        for(auto ngh:direc){
            int ii=i+ngh[0];
            int jj=j+ngh[1];
            if(!check(grid,ii,jj)) continue;
            int par=d.find(ii,jj);
            if(!umap.count(par))
                umap[par]=d.size[par];
        }
        int cnt=0;
        for(auto iter:umap) cnt+=iter.second;
        return cnt+1;
    }
    void dfs(vector<vector<int>>& grid,int i,int j,DSU&d){
        int par=d.find(i,j);
        for(auto ngh:direc){
            int ii=i+ngh[0];
            int jj=j+ngh[1];
            if(!check(grid,ii,jj)) continue;
            int par_ngh=d.find(ii,jj);
            if(par_ngh!=par){
                d.unite(i,j,ii,jj);
                dfs(grid,ii,jj,d);
            }
        }
        
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DSU d(n);
    
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                if(check(grid,i,j)){
                    dfs(grid,i,j,d);
                }
            }
        }
        
        int mx=0;
        for(auto itr:d.size) mx=max(mx,itr);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)
                    mx=max(mx,findStrength(grid,i,j,d));
            }
        }
        return mx;
        
    }
};