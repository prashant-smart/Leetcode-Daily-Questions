class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt=0;
        stack<int> st;
        st.push(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(st.size()){
                while(st.size()&&st.top()<=nums[i]) st.pop();
                if(st.size()!=0) cnt++;
                else st.push(nums[i]);
            }else{
                st.push(nums[i]);
            }
        }
        
        reverse(begin(nums),end(nums));
        int cnt1=0;
        stack<int> st1;
        st1.push(nums[0]);
        for(int i=1;i<nums.size();i++){
            
            if(st1.size()){
                
                while(st1.size()&&st1.top()>=nums[i]) st1.pop();
                // cout<<i;
                if(st1.size()!=0) cnt1++;
                else st1.push(nums[i]);
            }else{
                st1.push(nums[i]);
            }
        }
        cnt=min(cnt,cnt1);
        
        return cnt<=1;
    }
};