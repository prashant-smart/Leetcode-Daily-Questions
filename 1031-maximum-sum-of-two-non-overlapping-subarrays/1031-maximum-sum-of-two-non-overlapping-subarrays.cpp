class Solution {
public:
    int dp[1001][3][3];
    int helper(vector<int>& nums,int i, int firstLen, int secondLen,vector<int> &prefix) {
        if(!firstLen&&!secondLen) return 0;
        if(i>=nums.size()){
            return 0;
        }
        
        if(dp[i][!firstLen==0][!secondLen==0]!=-1) return dp[i][!firstLen==0][!secondLen==0];
        int ans=0;
        if(firstLen){
                if(i+firstLen-1<nums.size()){
                    ans=max({ans,prefix[i+firstLen]-prefix[i]+helper(nums,i+firstLen,0,secondLen,prefix),helper(nums,i+1,firstLen,secondLen,prefix)});
                }else{
                     ans=max({ans,helper(nums,i+1,firstLen,secondLen,prefix)});
                }
            
        }else{
                if(i+secondLen-1<nums.size()){
                    ans=max({ans,prefix[i+secondLen]-prefix[i]+helper(nums,i+secondLen,0,0,prefix),helper(nums,i+1,0,secondLen,prefix)});
                }else{
                     ans=max({ans,helper(nums,i+1,0,secondLen,prefix)});
                }
        }
        
        return dp[i][!firstLen==0][!secondLen==0]=ans;
    }
    
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        vector<int> prefix(nums.size()+1,0);
        for(int i=0;i<nums.size();i++){
            prefix[i+1]=nums[i]+prefix[i];
        }
        memset(dp,-1,sizeof(dp));
        int ans=helper(nums,0,firstLen,secondLen,prefix);
        memset(dp,-1,sizeof(dp));
        ans=max(ans,helper(nums,0,secondLen,firstLen,prefix));
        return ans;
        
    }
};