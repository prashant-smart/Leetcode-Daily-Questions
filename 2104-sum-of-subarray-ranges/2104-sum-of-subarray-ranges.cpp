class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        unsigned long long int leftSum=0,rightSum=0;
        stack<long long> leftSt,rihgtSt;
        vector< unsigned long long int> left(nums.size(),0),right(nums.size(),0);
        
        //max sum
        
        for(int i=0;i<nums.size();i++){ left[i]=0;right[i]=0;}
        
        for(int i=0;i<nums.size();i++){
            while(leftSt.size()&&nums[leftSt.top()]<nums[i]){
                left[i]=i-leftSt.top();
                leftSt.pop();
            }
            if(!leftSt.size()) left[i]=i;
            else left[i]=i-leftSt.top()-1;
            leftSt.push(i);
        }
        
        for(int i=nums.size()-1;i>=0;i--){
            while(rihgtSt.size()&&nums[rihgtSt.top()]<=nums[i]){
                rihgtSt.pop();
            }
            if(!rihgtSt.size()) right[i]=nums.size()-1-i;
            else right[i]=rihgtSt.top()-i-1;
            rihgtSt.push(i);
        }
        
        for(int i=0;i<nums.size();i++){
            leftSum+=nums[i]*(left[i]+1)*(right[i]+1);
        }
        //  for(auto i:left) cout<<i<<" ";
        // cout<<endl;
        // for(auto i:right) cout<<i<<" ";
        // cout<<endl;
        
        while(leftSt.size()) leftSt.pop();
        while(rihgtSt.size()) rihgtSt.pop();
        
//         //min sum
        
        for(int i=0;i<nums.size();i++){ left[i]=0;right[i]=0;}
        
        for(int i=0;i<nums.size();i++){
            
            while(leftSt.size()&&nums[leftSt.top()]>nums[i]){
                leftSt.pop();
            }
            if(!leftSt.size()) left[i]=i;
            else left[i]=i-leftSt.top()-1;
            leftSt.push(i);
        }
        
        for(int i=nums.size()-1;i>=0;i--){
            while(rihgtSt.size()&&nums[rihgtSt.top()]>=nums[i]){
                rihgtSt.pop();
            }
            if(!rihgtSt.size()) right[i]=nums.size()-1-i;
            else right[i]=rihgtSt.top()-i-1;
            rihgtSt.push(i);
        }
        
        // for(auto i:left) cout<<i<<" ";
        // cout<<endl;
        // for(auto i:right) cout<<i<<" ";
        // cout<<endl;
        for(int i=0;i<nums.size();i++){
            rightSum+=nums[i]*(left[i]+1)*(right[i]+1);
        }
        // cout<<rightSum<<" "<<leftSum;
        
        return leftSum-rightSum;
    }
};