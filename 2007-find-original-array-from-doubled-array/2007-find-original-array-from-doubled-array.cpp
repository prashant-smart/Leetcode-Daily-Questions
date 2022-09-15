class Solution {
public:
    vector<int> findOriginalArray(vector<int>& vec) {
        if(vec.size()%2!=0) return {};
        unordered_map<int,int> umap;
        for(auto i:vec){
            umap[i]++;
        }
        sort(begin(vec),end(vec));
        vector<int> ans;
        
        for(auto i:vec){
            // cout<<i<<" ";
            if(i==0){
                int k=umap[0]/2;
                
                umap[0]=0;
                while(k--){
                    ans.push_back(0);
                }
            }
            else if(umap[i*2]>0&&umap[i]>0){
                umap[i]--;
                ans.push_back(i);
                umap[i*2]--;
            }
        }
        if(ans.size()!=vec.size()/2) return {};
        return ans;
    }
};