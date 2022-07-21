

class RangeFreqQuery {
public:
    vector<unordered_map<int,int> > tree;
     vector<int> vec;
    unordered_map<string,int> dp;
    
    void buildTree(int str,int end,int curr){
        if(str==end){
            tree[curr][vec[str]]++;
            return ;
        }
        
        int mid=(str+end)/2;
        buildTree(str,mid,curr*2);
        buildTree(mid+1,end,curr*2+1);
        
      
        
        for(auto i:tree[2*curr]){
            tree[curr][i.first]+=i.second;
        }
        for(auto i:tree[2*curr+1]){
            tree[curr][i.first]+=i.second;
        }
        

        
    }
    RangeFreqQuery(vector<int>& arr) {
        vec=arr;
        tree.resize(4*arr.size());
        buildTree(0,arr.size()-1,1);
        
    }
    
    int query_(int &left, int &right, int &value,int str,int end,int curr) {
        if(end<left||right<str) return 0;
        if(left<=str&&right>=end){
            return tree[curr][value]; 
        }
        
        int mid=(str+end)/2;
        int lf=query_(left,right,value,str,mid,2*curr);
        int rt=query_(left,right,value,mid+1,end,2*curr+1);
        return lf+rt;
    }
    int query(int left, int right, int value){
       
        return query_(left,right,value,0,vec.size()-1,1);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */