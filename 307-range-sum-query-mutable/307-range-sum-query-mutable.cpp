class NumArray {
public:
    vector<int> tree;
    vector<int> arr;
     int size;
    void buildTree(int str,int end,int curr){
        if(str==end){
            tree[curr]=arr[str];
            return;
        }
        if(str>end) return ;
        
        int mid=(str+end)/2;
        buildTree(str,mid,2*curr);
        buildTree(mid+1,end,2*curr+1);
        tree[curr]=tree[2*curr]+tree[2*curr+1];
    }
    
    NumArray(vector<int>& nums) {
       size=nums.size();
        for(int i=0;i<4*size;i++)
            tree.push_back(0);
        arr=nums;
        buildTree(0,nums.size()-1,1);
    }
    
    void update_(int idx, int val,int str,int end,int curr) {
         if(str==end){
             tree[curr]=val;
             arr[str]=val;
             return;
         }
        if(str>end) return;
        
        int mid=(str+end)/2;
        if(mid>=idx){
            update_(idx,val,str,mid,2*curr);
        }else{
            update_(idx,val,mid+1,end,2*curr+1);
        }
        tree[curr]=tree[2*curr]+tree[2*curr+1];
    }
    
    void update(int idx, int val) {
        // cout<<size<<" ";
         update_(idx,val,0,size-1,1);
    }
    
    int sumRange_(int &left, int &right,int str,int end,int curr) {
        if(str>end) return 0;
        if(str>=left&&end<=right){ return tree[curr];}
        // if(str==end) return tree[curr];
        if(right<str||left>end) return 0;
        
        int mid=(str+end)/2;
        // cout<<str<<" "<<end<<" "<<mid<<endl;
        int lt=sumRange_(left,right,str,mid,2*curr);
        int rt=sumRange_(left,right,mid+1,end,2*curr+1);
        // cout<<lt+rt<<" ";
        return lt+rt;
    }
    int sumRange(int left, int right) {
        cout<<left<<" "<<right<<endl;
        return sumRange_(left,right,0,size-1,1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */