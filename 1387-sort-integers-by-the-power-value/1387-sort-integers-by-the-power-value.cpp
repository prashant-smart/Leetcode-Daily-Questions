class Solution {
public:
    int dp[1000000];
    int calcSetps(int num){
        if(num==1){
            return 0;
        }
        // cout<<num<<" ";
        if(dp[num]!=-1) return dp[num];
        if(num%2==0)
            return  dp[num]=1+calcSetps(num/2);
        return dp[num]=1+calcSetps(3*num+1);
    }
    int getKth(int lo, int hi, int k) {
        memset(dp,-1,sizeof(dp));
        vector<pair<int,int>> elmWithValue;
        for(int i=lo;i<=hi;i++){
            int steps=calcSetps(i);
            elmWithValue.push_back({steps,i});
        }
        sort(begin(elmWithValue),end(elmWithValue));
        return elmWithValue[k-1].second;
    }
};