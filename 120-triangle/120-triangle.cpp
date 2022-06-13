class Solution {
public:
    int minimumTotal(vector<vector<int>>& vec) {
        
        for(int i=1;i<vec.size();i++){
            for(int j=0;j<vec[i].size();j++){
                int a=INT_MAX,b=INT_MAX;
                if(j<vec[i-1].size() && j>=0){
                    a=vec[i-1][j];
                }
                if(j-1<vec[i-1].size()&&j-1>=0){
                    b=vec[i-1][j-1];
                }
                vec[i][j]=min(a,b)+vec[i][j];
            }
        }
        int ans=INT_MAX;
        for(auto iter:vec[vec.size()-1]){
            ans=min(ans,iter);
        }
        return ans;
        
        
    }
};