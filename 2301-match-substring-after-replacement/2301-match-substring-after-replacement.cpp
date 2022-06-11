class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mp) {
        unordered_map<char,unordered_set<char>> rel;
        for(auto i:mp){
            rel[i[0]].insert(i[1]);
        }
        
        // for(auto i:rel) cout<<i.first<<"->"<<i.second<<" ";
        for(int i=0;i<s.length()&&i+sub.length()<=s.length();i++){
            int k=0;
            bool isvalid=1;

            while(k<=sub.length()-1){
                
                if(sub[k]!=s[i+k]){
                    
                    if(rel[sub[k]].count(s[k+i])){
                        // cout<<sub[k]<<","<<s[i+k]<<" ";
                        isvalid=1;
                    }else{ isvalid=0;break;}
                }
                k++;
                // cout<<k<<" ";
                
            }
            if(isvalid) return 1;
        }
        return 0;
        
    }
};