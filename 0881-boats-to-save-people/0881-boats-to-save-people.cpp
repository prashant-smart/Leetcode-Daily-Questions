class Solution {
public:
    int numRescueBoats(vector<int>& p, int lim) {
        sort(begin(p),end(p));
        reverse(begin(p),end(p));
        int i=0,j=p.size()-1;
        
        int ans=0;
        while(i<=j){
            int weight=p[i];
            i++;
            if(i<=j){
                if(weight+p[j]<=lim){
                    j--;
                }
            }
            ans++;
        }
        return ans;
    }
};