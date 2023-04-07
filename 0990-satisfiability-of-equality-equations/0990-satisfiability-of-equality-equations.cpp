class Solution {
public:
    class DSU {
        int *parent;
        public:
        DSU(int N) {
            parent = new int[N];
            for (int i = 0; i < N; ++i)
                parent[i] = i;
        }
         int find(int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        }
         void unite(int x, int y) {
            parent[find(x)] = find(y);
        }
    };
    unordered_set<char> vis;
    void helper1(DSU &dsu,unordered_map<char,vector<char>> &in,char c){
        if(vis.count(c)){
            return;
        }
        vis.insert(c);
        for(auto ngh:in[c]){
            dsu.unite(c-'a',ngh-'a');
            helper1(dsu,in,ngh);
        }
    }
    bool helper2(DSU &dsu,unordered_map<char,vector<char>> &notin,char c){
        if(vis.count(c)){
            return 1;
        }
        vis.insert(c);
        int ans=1;
        for(auto ngh:notin[c]){
            // cout<<c<<" "<<ngh<<","<<dsu.find(c-'a')<<" "<<dsu.find(ngh-'a')<<endl;
            if(dsu.find(c-'a')==dsu.find(ngh-'a')) return 0;
            ans&=helper2(dsu,notin,ngh);
        }
        return ans;
    }
    bool equationsPossible(vector<string>& eq) {
        unordered_map<char,vector<char>> in,notin;
        for(auto i:eq){
          
            if(i[1]=='!'){
                // if(i[0]==i[3]) return 0;
                notin[i[0]].push_back(i[3]);
                notin[i[3]].push_back(i[0]);
            }else{
                in[i[0]].push_back(i[3]);
                in[i[3]].push_back(i[0]);
            }
        }
        DSU dsu(27);
        
        
        for(int i=0;i<=26;i++){
            if(!vis.count('a'+i)){
                helper1(dsu,in,'a'+i);
            }
        }
        vis.clear();
        for(int i=0;i<=26;i++){
            if(!vis.count('a'+i)){
                if(!helper2(dsu,notin,'a'+i)) return 0; 
            }
        }
        return 1;
    }
};