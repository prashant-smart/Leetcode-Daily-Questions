class Solution {
public:
    int dp[300+1][3000+1];
   
    long long helper(vector<int> &vec,int i,int num){
        if(num==0) return 0;
        if(num<0||i>=vec.size()) return INT_MAX;
        
        if(dp[i][num]!=-1) return dp[i][num];
        
        long long ans=INT_MAX;
        int idx=i;
            ans=min({ans,1+helper(vec,idx,num-vec[idx]),1+helper(vec,idx+1,num-vec[idx]),helper(vec,idx+1,num)});
        return dp[i][num]=ans;
    }
    int minimumNumbers(int num, int k) {
        unordered_map<int,int> sumMap;
        if(num==0){
            
            return 0;
        }
        int n=k;
        vector<int>vec;
        while(1){
            if(n>num) break;
            
            if(n!=0&&n%10==k){
                vec.push_back(n);
            }
            n+=10;
        }
        memset(dp,-1,sizeof(dp));
        // for(auto i:vec) cout<<i<<" ";
        // cout<<vec.size()<<" ";
        long long ans= helper(vec,0,num);
        if(ans>=INT_MAX) return -1;
        return ans;
    }
};