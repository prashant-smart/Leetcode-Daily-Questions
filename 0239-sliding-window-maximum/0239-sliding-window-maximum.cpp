class Solution {
public:

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> st;
        int i=0;
        for(;i<k;i++){
            st.insert(nums[i]);
        }
        vector<int> ans;
        int j=0;
        for(;i<=nums.size();){
            int grt=*--st.end();
            ans.push_back(grt);
            if(i==nums.size()) 
                break;
            auto pos=st.find(nums[j]);
            st.erase(pos);
            st.insert(nums[i]);
            i++,j++;
        }
        return ans;
    }
};