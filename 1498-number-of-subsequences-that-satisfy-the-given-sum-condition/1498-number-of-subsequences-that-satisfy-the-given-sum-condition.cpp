class Solution {
public:
    int lim=1000000000+7;
    
    


 
/* Iterative Function to calculate (x^y)%p in O(log y) */
int POW(long long x, unsigned int y)
{
    int res = 1;     // Initialize result
 
    x = x % lim; // Update x if it is more than or
                // equal to p
  
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % lim;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % lim;
    }
  return res;
}
    int numSubseq(vector<int>& nums, int target) {
        sort(begin(nums),end(nums));
        int  cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]*2>target) break;
            auto range=upper_bound(begin(nums)+i,end(nums),target-nums[i]);
            range--;
            int j=range-begin(nums);
            if(i<=j){
                cout<<j-i+1;
                cnt=(cnt+POW(2,j-i)%lim)%lim;
            }
        }
        return cnt;
    }
};