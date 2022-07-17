class Solution {
public:
       static bool cmp(pair<string,int>&x,pair<string,int>&y){
        for(int i=0;i<x.first.length();i++){
            if(x.first[i]-'0'>y.first[i]-'0'){
                return 0;
            }else if(x.first[i]-'0'<y.first[i]-'0'){
                return 1;
            }
        }
        
        return x.second<y.second;
    }
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<string> temp;
        for(auto i:nums){
            reverse(begin(i),end(i));
            temp.push_back(i);
        }
        
        // unordered_map<int, priority_queue< pair<string,int>,vector<pair<string,int>>,greater<pair<string,int>>> > umap;
        unordered_map<int,vector<pair<string,int>> > umap;
        int k=0;
        for(auto &i:temp){
            for(int j=i.length();j>0;j--){
                
                
                reverse(begin(i),end(i));
                
                umap[j].push_back({i,k});
                reverse(begin(i),end(i));
                i.pop_back();
            
                // cout<<umap[j].back().first<<" ";
            }
            
            k++;
        }
        
      for(auto &i:umap){
          sort(begin(i.second),end(i.second),cmp);
      }
        
        vector<int>ans;
         k=0;
        for(auto &pr:queries){
            
            auto vv=umap[pr[1]];
            // cout<<pr[1]<<" "<<pr[0]<<endl;
            // for(auto i:vv)cout<<i.first<<" ";
            // cout<<endl;
            // while(pr[0]--){
            //     ans[k]=vv.top().second;
            //     vv.pop();
            // }
            ans.push_back(vv[pr[0]-1].second);
            k++;
        }
        return ans;
    }
};