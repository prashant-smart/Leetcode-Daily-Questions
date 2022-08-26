class Solution {
public:
    bool reorderedPowerOf2(int n) {
        long long int i;
        unordered_set<long long > st;
        unordered_map<int,int>isavl,check;
        for(i=0;i<=30;i++){
            st.insert(pow(2,i));
        }
        string p=to_string(n);
        for(auto i:p){
            isavl[i-'0']++;
            
        }
        
        for(auto i:st){
            // cout<<i<<" ";
            bool c=1;
            for(auto k:to_string(i)){
                check[k-'0']++;
            }
            
            if(check==isavl) return 1;
            check.clear();
        }
        return 0;
    }
};