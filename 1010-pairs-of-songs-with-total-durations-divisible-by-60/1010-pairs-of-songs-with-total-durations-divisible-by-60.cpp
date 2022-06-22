class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        for(auto &i:time) i%=60;
        unordered_map<int,int> umap;
        for(auto i:time) umap[i]++;
        
        unsigned long long int ans=0;
        for(auto i:time){
            if(umap.count((60-i)%60)){
                if(i==(60-i)%60){
                    unsigned long long int n=umap[i]-1;
                    ans+=n*(n+1)/2;
                    umap.erase(i);
                }else{
                    ans+=umap[i]*umap[(60-i)%60];
                    umap.erase(i);
                    umap.erase(60-i);
                }
            }
        }
        return ans;
    }
};