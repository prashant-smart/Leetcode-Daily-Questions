class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
       int a=INT_MAX,b=INT_MAX;
        for(auto iter:nums)
        {
            if(a>=iter)
                a=iter;
            else if(b>=iter)
                b=iter;
            else return true;
        }
        return false; 
    }
};