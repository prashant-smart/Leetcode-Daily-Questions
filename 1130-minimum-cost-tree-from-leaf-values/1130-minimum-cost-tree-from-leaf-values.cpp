class Solution {
public:
    unordered_map<string,pair<int,int>> dp;
    pair<int,int> helper(vector<int> &arr,int i,int j){
        if(j-i==1){
            return {arr[i]*arr[j],max(arr[i],arr[j])};
        }
        if(i==j){
            return {0,arr[i]};
        }
        string key=to_string(i)+" "+to_string(j);
        if(dp.count(key)) return dp[key];
        
        int ans=INT_MAX;
        int mx=INT_MAX;
        for(int idx=i;idx<j;idx++){
            auto left=helper(arr,i,idx);
            auto right=helper(arr,idx+1,j);
            // cout<<left.first<<" "<<left.second<<" "<<right.first<<" "<<right.second<<endl;
            if(left.first+right.first+(left.second*right.second)<ans){
                ans=left.first+right.first+left.second*right.second;
                mx=max(left.second,right.second);
            }
        }
        return dp[key]={ans,mx};
    }
    int mctFromLeafValues(vector<int>& arr) {
        auto p=helper(arr,0,arr.size()-1);
        return p.first;
    }
};