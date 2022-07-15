
class DSU{
    public:
    unordered_map<int,int> parent,strength;
    DSU(int n){
        for(int i=0;i<n;i++){
            parent[i]=-1;
            strength[i]=1;
        }
    }
    
    int find(int n){
        if(parent[n]==-1) return n;
        return find(parent[n]);
    }
    
    void unite(int n1,int n2,int &cnt){
        int s1=find(n1);
        int s2=find(n2);
        
        if(s1==s2) cnt++;
        else{
            if(strength[s2]>strength[s1]){
                parent[s1]=s2;
                strength[s2]+=strength[s1];
            }else{
                parent[s2]=s1;
                strength[s1]+=strength[s2];
            }
        }
    }
    
    int countParent(){
        int cnt=0;
        for(auto pr:parent){
            if(pr.second==-1) cnt++;
        }
        return cnt;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
       DSU obj=DSU(n);
        int cnt=0;
        for(auto pr:connections){
            obj.unite(pr[0],pr[1],cnt);
        }
        
        int k=obj.countParent()-1;
        if(k==-1) return 0;
        cout<<k<<" "<<cnt<<" ";
        return (cnt>=k)?k:-1;
    }
};