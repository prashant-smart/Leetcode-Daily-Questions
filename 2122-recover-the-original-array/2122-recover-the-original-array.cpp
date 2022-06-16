class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
             int k=(nums[i]-nums[0])/2;
            if((nums[i]-nums[0])%2==1 || k<1)continue;

            bool possible=true;
            vector<bool> left(n,true);
            vector<int> temAns;
            int upper=i;
        
            for(int lower=0;lower<n;lower++){
                if(!left[lower])continue;
                if(upper==lower)upper++;
                while(upper<n && nums[upper]-nums[lower]<=2*k){
                if(nums[upper]-nums[lower]==2*k){
                    temAns.push_back(nums[lower]+k);
                    left[upper]=left[lower]=false;
                    upper++;
                    break;
                }
                    upper++;
                }
                if(left[lower]){
                    possible=false;
                    break;
                }
                
            }
            if(possible){
                ans=temAns;
                break;
            }
        }
        return ans;
    }
};