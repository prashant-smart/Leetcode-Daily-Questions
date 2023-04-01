class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1,mid;
        while(high-low>1){
            mid=(low+high)/2;
            if(nums[mid]<target)
                low=mid+1;
            else high=mid;
        }
        if(nums[high]==target) return high;
        else if(nums[low]==target) return low;
        return -1;
    }
};