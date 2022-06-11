class Solution {
public:
    
    unordered_map<string,int> dp;
    int findMaxSum(vector<int>& arr, int& k,int pos,int currMax,int p){
        if(pos==arr.size()){
            return (currMax)*(k-p);
        }
        string key=to_string(pos)+" "+to_string(p);
        
        if(dp.count(key)) return dp[key];
        
        int ans=0;
        if(p!=0)
            ans=max({ans,(currMax)*(k-p)+findMaxSum(arr,k,pos+1,arr[pos],k-1),findMaxSum(arr,k,pos+1,max(currMax,arr[pos]),p-1)});
        else ans=max({ans,(currMax)*(k-p)+findMaxSum(arr,k,pos+1,arr[pos],k-1)});
        dp[key]=ans;
        return ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
    
        return findMaxSum(arr,k,0,0,0);
    }
};