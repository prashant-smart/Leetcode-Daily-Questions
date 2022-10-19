class Solution {
public:
    static bool cmp(pair<int,string> &x1,pair<int,string>&x2){
        return x1.first>x2.first;
    }
 vector<string> topKFrequent(vector<string>& words, int k) {
	unordered_map<string,int> umap;
     for(auto i:words) umap[i]++;
     
     vector<pair<int,string>> vec;
     for(auto i:umap) vec.push_back({i.second,i.first});
     
     sort(begin(vec),end(vec),cmp);
     
     map<int,vector<string>> mp;
     for(auto i:vec){
        
         
         mp[i.first].push_back(i.second);
        
     }
     for(auto &i:mp){
        sort(begin(i.second),end(i.second)); 
     }
     vector<string> ans;
     
     
     
     for(auto &i:mp){
         while(i.second.size()){
             ans.push_back(i.second.back());
             i.second.pop_back();
         }
     }
     
     reverse(begin(ans),end(ans));
     int size=ans.size(); 
     while(size!=k){
         ans.pop_back();
         size--;
     }
     return ans;
     
     
     
}
};