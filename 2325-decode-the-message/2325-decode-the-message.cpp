class Solution {
public:
    string decodeMessage(string key, string message) {
        char a='a';
        unordered_map<char,char> umap;
        for(auto i:key){
            if(!umap.count(i)&&i!=' '){
                umap[i]=a;
                a++;
            }
        }
        
        string ans;
        for(auto i:message){
            if(i==' ') ans.push_back(' ');
            else
                ans.push_back(umap[i]);
        }
        return ans;
    }
};