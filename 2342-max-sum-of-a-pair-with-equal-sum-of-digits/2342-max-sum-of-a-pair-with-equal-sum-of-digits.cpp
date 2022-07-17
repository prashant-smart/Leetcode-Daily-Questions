class Solution {
public:
    long long h(int num){
        long long sum=0;
        while(num){
            sum+=num%10;
            num/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<long long,vector<int>> umap;
        for(auto i:nums){
            umap[h(i)].push_back(i);
        }
        
        for(auto &i:umap){
            sort(begin(i.second),end(i.second));
        }
        int ans=-1;
        
        for(auto i:umap){
            if(i.second.size()>1){
                ans=max(ans,i.second[i.second.size()-1]+i.second[i.second.size()-2]);
            }
        }
        return ans;
    }
};