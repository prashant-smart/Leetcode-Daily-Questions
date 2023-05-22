class Solution {
public:
    int search(vector<int>& nums, int tar) {
        int pivot=0;
        int l=0,h=nums.size()-1;
        if(nums.size()<=3){
            for(int i=0;i<nums.size();i++){
                if(nums[i]==tar) return i;
            }
            return -1;
        }
        while(h-l>1){
            int mid=(h+l)/2;
            if(nums[l]<nums[mid]){
                l=mid;
            }else if(nums[l]>nums[mid]){
                // cout<<l<<" "<<mid<<" "<<h<<endl;
                h=mid;
                pivot=mid;
            }
        }
        if(nums[h]<nums[l]) pivot =h;
        
        auto f=lower_bound(nums.begin(), nums.begin()+pivot, tar);
        auto s=lower_bound(nums.begin()+pivot, nums.end(), tar);
        
        if(tar>=nums[0]&&f!=nums.begin()+pivot&&nums[f-begin(nums)]==tar) return f-begin(nums);
        else if(s!=nums.end()&&nums[s-begin(nums)]==tar) return s-begin(nums);
        return -1;
    }
};