class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int cnt=0;
        int ans=0;
        int prev=0;
        for(int i=0;i<bank.size();i++){
            int curr=0;
            for(int j=0;j<bank[0].size();j++){
                if(bank[i][j]=='1'){
                    curr++;
                }
            }
            
            if(curr!=0) cnt++;
            
            if(curr!=0){
                if(prev!=0)
                    ans+=prev*curr;
                prev=curr;
            }
        }
        if(cnt<=1) return 0;
        return ans;
        
    }
};