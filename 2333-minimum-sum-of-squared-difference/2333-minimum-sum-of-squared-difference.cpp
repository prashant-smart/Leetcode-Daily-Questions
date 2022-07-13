class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        unordered_map<long long,long long> umap;
        priority_queue<int> pq; 
        for(int i=0;i<nums1.size();i++){
            if(!umap.count(abs(nums1[i]-nums2[i]))){
                pq.push(abs(nums1[i]-nums2[i]));
            }
            umap[abs(nums1[i]-nums2[i])]++;
        }
        
        
        long long ans=0;
        long long k=k1+k2;
        while(pq.size()&&k){
           
            int tp=pq.top();
            pq.pop();
            if(tp==0) continue;
             // cout<<tp<<" "<<umap[tp]<<endl;
            
            if(!umap.count(tp-1)&&tp-1!=0){
                pq.push(tp-1);
            }
            
            if(tp-1!=0){
                umap[tp-1]+=min({umap[tp],k});
            }
            
            int val=min(umap[tp],k);
            umap[tp]-=min(umap[tp],k);
            k-=val;
            
        }
        
        for(auto i:umap){
            ans+=i.second*i.first*i.first;
        }
        return ans;
        
    }
};