class Solution {
public:
    bool isvalid(vector<vector<int>>& grid,int i,int j){
        int n=grid.size();
        int m=grid[0].size();
        if(i>=0&&i<n&&j>=0&&j<m) return 1;
        return 0;
    }
    vector<vector<int>> direc={{0,1},{0,-1},{1,0},{-1,0}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        
        vector<vector<int>> dis(n,vector<int> (m,INT_MAX));
        set<vector<int>> st;
        st.insert({0,0,0});
        dis[0][0]=0;
        while(st.size()){
            auto tp=*(st.begin());
            st.erase(tp);
            // cout<<tp[1]<<" "<<tp[2]<<endl;
            for(auto ngh:direc){
                int i=ngh[0]+tp[1];
                int j=ngh[1]+tp[2];
                if(!isvalid(heights,i,j)) continue;
                
                int cost=abs(heights[i][j]-heights[tp[1]][tp[2]]);
                
                if( max(tp[0],cost)<dis[i][j]){
                    
                    vector<int> v={dis[i][j],i,j};
                    auto f=st.find(v);
                    if(f!=st.end())
                        st.erase(f);
                    
                    v={max(tp[0],cost),i,j};
                    dis[i][j]=v[0];
                    st.insert(v);
                    
                }
                // cout<<st.size()<<" ";
            }
        }
        return dis[n-1][m-1];
        
    }
};