class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> umap;
        for(auto s:strs){
            string cpy=s;
            sort(begin(cpy),end(cpy));
            umap[cpy].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto iter:umap){
            ans.push_back(iter.second);
        }
        return ans;
    }
};