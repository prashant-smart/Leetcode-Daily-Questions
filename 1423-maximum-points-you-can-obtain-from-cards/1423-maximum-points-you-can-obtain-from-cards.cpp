class Solution {
public:
    int maxScore(vector<int>& vec, int k) {
        for(int i=1;i<vec.size();i++){
            vec[i]+=vec[i-1];
        }
        if(vec.size()==k){
            return vec[vec.size()-1];
        }
        int low=0,high=vec.size()-k-1;
        int ans=0;
        int total=vec[vec.size()-1];
        while(high<vec.size() && high>=low){
            int refLow=(low==0)? 0:vec[low-1];
            ans=max(total-(vec[high]-refLow),ans);
            high++;
            low++;
        }
        return ans;
    }
};