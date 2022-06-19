class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        unordered_map<string,set<string>> umap;
        for(int i=0;i<products.size();i++){
            string val=products[i];
            string key;
            for(int j=0;j<val.length();j++){
                key.push_back(val[j]);
                umap[key].insert(val);
                cout<<key<<" ";
            }
            
        }
        cout<<endl;
        vector<vector<string>> ans;
        string key;
        for(auto i:searchWord){
            vector<string> v;
            key.push_back(i);
            cout<<key<<" ";
            for(auto itr:umap[key]){
                if(v.size()==3) break;
                v.push_back(itr);
            }
            ans.push_back(v);
        }
        return ans;
    }
};