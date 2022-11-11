class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto ip=unique(begin(nums),end(nums));
        return distance(nums.begin(), ip);
    }
};