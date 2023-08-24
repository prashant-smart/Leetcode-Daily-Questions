class Solution {
public:
    static bool cmp(vector<int>&x,vector<int>&y){
        if(x[0]!=y[0]) return x[0]<y[0];
        else if(x[1]!=y[1]) return x[1]<y[1];
        return x[2]>y[2];
    }
    int dp[100001];
    int helper(vector<vector<int>>& vec,vector<int>&fl,int i){
        if(i>=vec.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=0;
        ans=max({vec[i][2]+helper(vec,fl,fl[i]),helper(vec,fl,i+1)});
        return dp[i]=ans;
    }
    int maximizeTheProfit(int n, vector<vector<int>>& vec) {
        sort(begin(vec),end(vec),cmp);
        vector<int> v;
        for(auto i:vec){
            v.push_back(i[0]);
        }
        vector<int> fl(vec.size());
        for(int i=vec.size()-1;i>=0;i--){
            auto iter=upper_bound(begin(v)+i+1,end(v),vec[i][1]);
            
            if(iter==end(v)){
                fl[i]=vec.size();
            }else{
                fl[i]=iter-begin(v);
            }
            
        }
        memset(dp,-1,sizeof dp);
        return helper(vec,fl,0);
    }
};