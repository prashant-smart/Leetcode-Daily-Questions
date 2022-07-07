class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        vector<int> vec(32,0);
        for(auto i:nums){
            int pos=0;
            while(i){
                vec[pos]+=(i&1);
                pos++;
                i>>=1;
            }
        }
        
        for(int i=0;i<32;i++){
            if(vec[i]%2==0&&vec[i]!=0){
                
                for(auto &elm:nums){
                    if(((elm>>i)&1)==1){
                        // cout<<elm<<" ";
                        int mask=1<<i;
                        mask=~mask;
                        elm&=mask;
                        break;
                    }
                }
            }
        }
        // cout<<endl;
        
        int ans=nums[0];
        // cout<<vec[0]<<" ";
        for(int i=1;i<nums.size();i++){
            // cout<<vec[i]<<" ";
            ans^=nums[i];
        }
        return ans;
    }
    
};