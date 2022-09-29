class Solution {
public:
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto comp=[&x](int a,int b){
            if(abs(a-x)==abs(b-x)) return a<b;
            return abs(a-x)<abs(b-x);
        };
        sort(begin(arr),end(arr),comp);
        for(int i=arr.size()-1;i>=0&&i!=k-1;i--){
            arr.pop_back();
        }
        sort(begin(arr),end(arr));
        return arr;
    }
};