class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        map<int,vector<int>> umap;
        vector<pair<int,int>> temp;
        
        
        priority_queue<pair<int,int>> pq;
        
        
        
        for(int i=0;i<profits.size();i++){
            temp.push_back({capital[i],profits[i]});    
        }
        sort(begin(temp),end(temp));
        int idx=-1;
        for(auto i:temp){
            
            if(i.first>w) break;
            idx++;
        }
        if(idx==-1)return w;
        // cout<<idx<<" ";
        for(int i=0;i<=idx;i++){
            umap[temp[i].first].push_back(temp[i].second);
            
        }
        
        for(auto &i:umap){
            sort(begin(i.second),end(i.second));
        }
        // cout<<idx<<" ";
        for(int i=0;i<=idx;i++){
            
            if(i!=0&&temp[i].first==temp[i-1].first) continue;
            // cout<<umap[temp[i].first].back()<<" ";
            pq.push({umap[temp[i].first].back(),temp[i].first});
            // cout<<i<<" ";
            if(umap[temp[i].first].size())
                umap[temp[i].first].pop_back();
        }
        
        while(k--&&pq.size()){
           
            int sec=pq.top().second;
            int val=pq.top().first;
            pq.pop();
            // cout<<sec<<" "<<val<<endl;
            w+=val;
            if(umap[sec].size()){
                pq.push({umap[sec].back(),sec});
                umap[sec].pop_back();
            }
            int p=idx;
            while(p<temp.size()){
                if(p==temp.size()-1){
                    break;
                }else{
                    if(temp[p+1].first<=w) p++;
                    else break;
                }
            }
            
             // cout<<k<<" ";
            for(int pp=idx+1;pp<=p;pp++){
                umap[temp[pp].first].push_back(temp[pp].second);
            }
            
            if(idx<p){
                idx++;
                for(idx;idx<=p;idx++){
                    pq.push({umap[temp[idx].first].back(),temp[idx].first});
                    umap[temp[idx].first].pop_back();
                }
            }
            
            idx=p;
            // cout<<w<<" ";
            
        }
        return w;
    }
};