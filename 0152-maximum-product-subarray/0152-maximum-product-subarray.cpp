class Solution {
public:
    int mx=INT_MIN;
    unordered_map<string,int> dp;
   int helper(vector<int>& nums,int i,int s){
       if(i==nums.size()) return 1;
       string key=to_string(i);
       if(dp.count(key+" "+to_string(s))) return dp[key+" "+to_string(s)];
       
       
           int a=(nums[i]*helper(nums,i+1,1));
            int b=(nums[i]*helper(nums,i+1,0));
            int Mx=max(a,max(b,nums[i]));
            int Mn=min(a,min(b,nums[i]));
           dp[key+" "+to_string(1)]=Mx;
           dp[key+" "+to_string(0)]=Mn;
            
            mx=max(Mx,mx);
           if(s==0) return Mn;
           else return Mx;
       
   }
    
   int maxProduct(vector<int>& nums) {
        // memset(dp,-1,sizeof(dp));
       helper(nums,0,1);
       
        return mx;
    }
};