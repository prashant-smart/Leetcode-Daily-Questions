dsu for grid
​
```
class DSU{
public:
vector<int> parent;
vector<int> size;
int N;
DSU(int n){
parent.resize(n*n+n);
N=n;
size.resize(n*n+n);
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
parent[i*n+j]=i*n+j;
size[i*n+j]=1;
}
}
}
int find(int i,int j){
// cout<<i<< " "<<j<<endl;
if(parent[i*N+j]==i*N+j) return i*N+j;
int par=parent[i*N+j];
int pi=par/N;
int pj=par%N;
return parent[i*N+j]=find(pi,pj);
}
void unite(int i1,int j1,int i2,int j2){
int p1=find(i1,j1);
int p2=find(i2,j2);
if(size[p2]>size[p1]){
parent[p1]=p2;
size[p2]+=size[p1];
}else{
parent[p2]=p1;
size[p1]+=size[p2];
}
}
};
```
​