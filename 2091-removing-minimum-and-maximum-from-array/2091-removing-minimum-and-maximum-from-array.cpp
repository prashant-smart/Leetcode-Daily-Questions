class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mx=INT_MIN,mn=INT_MAX;
        int mxIdx,mnIdx;
        for(int i=0;i<nums.size();i++){
            if(mn>nums[i]){
                mn=nums[i];
                mnIdx=i;
            }
            if(mx<nums[i]){
                mx=nums[i];
                mxIdx=i;
            }
        }
        if(mnIdx==mxIdx) return min(mnIdx+1,(int)nums.size()-mnIdx);
        vector<int> first,sec;
        for(auto i:nums){
            first.push_back(i);
            sec.push_back(i);
        }
        
        
        int ans1=0,ans2=0;
        for(int i=0;i<nums.size();i++){
            if(i==mnIdx){
                ans1=i+1;
                ans1+=min(mxIdx-mnIdx,(int)nums.size()-mxIdx);
                break;
            }else if(i==mxIdx){
                ans1=i+1;
                ans1+=min(mnIdx-mxIdx,(int)nums.size()-mnIdx);
                break;
            }
            
        }
        
        for(int i=nums.size()-1;i>=0;i--){
            if(i==mnIdx){
                ans2=nums.size()-i;
                ans2+=min(mnIdx-mxIdx,mxIdx+1);
                break;
            }else if(i==mxIdx){
                ans2=nums.size()-i;
                ans2+=min(mxIdx-mnIdx,mnIdx+1);
                break;
            }
        }
        return min(ans1,ans2);
        
        
    }
};