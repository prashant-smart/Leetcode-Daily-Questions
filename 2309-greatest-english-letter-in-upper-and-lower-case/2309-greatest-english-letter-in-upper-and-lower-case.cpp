class Solution {
public:
    #include <cctype>
    string greatestLetter(string s) {
        map<char,int> umap;
        unordered_map<int,int> mp;
        
        for(auto i:s){
            if(i>=65&&i<=90){
                umap[i]++;
            }else{
                
                mp[i-'a']++;
            }
        }
        
        string ans;
        
        for(auto i:umap){
           
            if(mp[i.first-'A']){
                // cout<<i.first<<" ";
                if(ans.length())
                    ans.pop_back();
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};