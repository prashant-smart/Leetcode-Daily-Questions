class Solution {
public:
    void remove(multiset<int>&my_multiset,int value){
            auto itr = my_multiset.find(value);
            if(itr!=my_multiset.end()){
                my_multiset.erase(itr);
    }

    }
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
            if(i==nums.size()) break;
            
            remove(st,nums[j]);
            st.insert(nums[i]);
            i++,j++;
        }
        return ans;
    }
};