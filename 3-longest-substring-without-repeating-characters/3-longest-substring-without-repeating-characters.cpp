class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> umap;
        int ans=0;
        int i=0;
        for(int j=0;j<s.length();j++){
            if(!umap.count(s[j])){
                umap[s[j]]=j;
            }else{
                if(i<=umap[s[j]]){
                    i=umap[s[j]]+1;
                }
                umap[s[j]]=j;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};