class Solution {
public:
    int countPoints(string rings) {
        unordered_map<int,unordered_set<char>> umap;
        for(int i=0;i<rings.length();i++){
            umap[rings[i+1]-'0'].insert(rings[i]);
            i+=1;
        }
        int cnt=0;
        for(auto i:umap){
            if(i.second.size()==3) cnt++;
        }
        return cnt;
    }
};