class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long s) {
        sort(begin(potions),end(potions));
        
        vector<int> ans;
        vector<long long> p(potions.size(),0);
        for(int i=0;i<potions.size();i++){
            
                p[i]=potions[i];
        }
        for(auto i:spells){
            cout<<i<<" ";
            long long low=0,high=potions.size()-1;
            while(high-low>1){
                int mid=low+(high-low)/2;
                if(p[mid]*i>=s){
                    high=mid;
                }else low=mid+1;
            }
            long long val=0;
            if(p[low]*i>=s){
                val=max(val,(long long)potions.size()-low);
            }
            if(p[high]*i>=s){
                val=max(val,(long long)potions.size()-high);
            }
            ans.push_back(val);
        }
        return ans;
    }
};