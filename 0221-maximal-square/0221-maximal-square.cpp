class Solution {
public:
    int maximalSquare(vector<vector<char>>& vec) {
        int n=vec.size();
        int m=vec[0].size();
        vector<vector<int>> mat(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                mat[i][j]=vec[i-1][j-1]-'0';
            }
        }
        
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                mat[i][j]+=(mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1]);
            }
        }
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         cout<<mat[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        long long ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int mn=min(i,j);
                for(int k=0;k<mn;k++){
                    long long val=mat[i][j]-mat[i][j-k-1]-mat[i-k-1][j]+mat[i-k-1][j-k-1];
                    // cout<<i<<" "<<j<<" "<<i-k<<" "<<j-k<<" "<<val<<endl;
                    if(val==(k+1)*(k+1))
                        ans=max(ans,val);
                }
            }
        }
        return ans;
    }
    
};