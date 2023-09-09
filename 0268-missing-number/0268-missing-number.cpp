class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(begin(nums),end(nums));
        // for(auto i:nums) cout<<i<<" ";
        int r=0;
        for(int i=0;i<nums.size();i++){
            if(r!=nums[i]) return r;
            r++;
        }
        return r;
    }
};