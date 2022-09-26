class DSU{
    public:
    unordered_map<int,int> strength,parent;
    
    DSU(){
    }
    
    int find(int n){
        if(!parent.count(n)) return n;
        return find(parent[n]);
    }
    
    
    void unite(int n1,int n2){
        int s1=find(n1);
        int s2=find(n2);
        
        if(!strength.count(n1))strength[n1]=1;
        if(!strength.count(n2))strength[n2]=1;
        
        if(s1!=s2){
            if(strength[s1]>strength[s2]){
                parent[s2]=s1;
                strength[s1]+=strength[s2];
            }else{
                parent[s1]=s2;
                strength[s2]+=strength[s1];
            }
        }
    }
    
    
    
};


class Solution {
public:
    
    static bool cmp(string &x,string &y){
        return x[1]=='='&&y[1]=='!';
    }
    
    bool equationsPossible(vector<string>& equations) {
        
        sort(begin(equations),end(equations),cmp);
        DSU obj=DSU();
        for(auto i:equations){
            int n1=i[0]-'0';
            int n2=i[3]-'0';
            
            if(i[1]=='='&&i[2]=='='){
                obj.unite(n1,n2);
            }else{
                if(obj.find(n1)==obj.find(n2)){
                    return 0;
                }
            }
        }
        return 1;
    }
};