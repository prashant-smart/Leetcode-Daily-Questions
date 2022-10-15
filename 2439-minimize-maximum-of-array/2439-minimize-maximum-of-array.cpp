class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
    long long minmax = nums[0], sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        if (nums[i] > minmax)
            minmax = max(sum / (i + 1) + (sum % (i + 1) ? 1 : 0), minmax);
    }
    return minmax;
}
};