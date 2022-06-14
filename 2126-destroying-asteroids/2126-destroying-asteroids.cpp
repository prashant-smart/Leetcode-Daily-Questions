class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        sort(begin(a),end(a));
        long long m=mass;
        for(auto i:a){
            if(m<i) return 0;
            m+=i;
        }
        return 1;
    }
};