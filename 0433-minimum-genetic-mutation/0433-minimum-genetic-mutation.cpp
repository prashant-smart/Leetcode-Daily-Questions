class Solution {
public:
    
    
    int helper(string startGene, string &endGene, vector<string>& bank,int k=0){
        // cout<<k<<" ";
        if(startGene==endGene) return 0;
        if(k>=bank.size()) return INT_MAX/2;
        
        
        int ans=INT_MAX/2;
        for(auto i:bank){
            int cnt=0;
            for(int ii=0;ii<8;ii++){
                if(i[ii]!=startGene[ii]) cnt++;
            }
            // cout<<i<<" "<<startGene<<" "<<cnt<<" ";
            if(cnt==1){
                ans=min(ans,1+helper(i,endGene,bank,k+1));
            }
            
        }
        return ans;
    }
    
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        
        int ans=helper(startGene,endGene,bank);
        return ans>=INT_MAX/2?-1:ans;
        
    }
};