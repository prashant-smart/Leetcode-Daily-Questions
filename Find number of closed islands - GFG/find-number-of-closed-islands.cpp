//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    vector<vector<int>> direc={{-1,0},{0,-1},{1,0},{0,1}};
    void helper(vector<vector<int>>& mat, int i, int j,int clr){
        if(i>=mat.size()||j>=mat[0].size()||i<0||j<0||mat[i][j]!=1){
            return;
        }
        mat[i][j]=clr;
        for(auto d:direc){
            helper(mat,i+d[0],j+d[1],clr);
        }
        
    }
    int closedIslands(vector<vector<int>>& mat, int N, int M) {
        for(int i=0;i<N;i++){
            if(mat[i][0]==1){
                helper(mat,i,0,2);
            }
            if(mat[i][M-1]==1){
                helper(mat,i,M-1,2);
            } 
        }
        
        for(int i=0;i<M;i++){
            if(mat[0][i]==1){
                helper(mat,0,i,2);
            }
            if(mat[N-1][i]==1){
                helper(mat,N-1,i,2);
            } 
        }
        
        int ans=0;
        int clr=3;
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(mat[i][j]==1){
                    // cout<<i<<" "<<j<<endl;
                    helper(mat,i,j,clr);
                    clr++;
                    ans++;
                }
            }
        }
        
        
       return ans; 
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends