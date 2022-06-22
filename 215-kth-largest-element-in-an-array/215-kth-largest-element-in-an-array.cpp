class Solution {
public:
     int findKthLargest(vector<int>& nums, int k) {
        make_heap(begin(nums),end(nums));
         int n;
        while(k--){
            n=nums.front();
            pop_heap(begin(nums),end(nums));
            nums.pop_back();
        }
         return n;
    }
    
};