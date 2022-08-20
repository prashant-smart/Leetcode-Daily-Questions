class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int prev_max = -1;
        for(int i = 1; i < nums.size(); i++) {
                if(nums[i] < prev_max) {
                    return false;
                }
            else {
                prev_max = max(prev_max, nums[i-1]);
            }
        }
        return true;
    }
};