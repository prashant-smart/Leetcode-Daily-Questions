class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int times) {
        int n=security.size();
        vector<int> left(n,0),right(n,0);
        
        int cnt=0;
        for(int i=1;i<n;i++){
            if(security[i]<=security[i-1]){
                cnt++;
                left[i]=cnt;
            }else {
                cnt=0;
            }
        }
        cnt=0;
        for(int i=n-2;i>=0;i--){
            if(security[i]<=security[i+1]){
                cnt++;
                right[i]=cnt;
            }else {
                cnt=0;
            }
        }
        
        // for(auto i:left) cout<<i<<" ";
        // cout<<endl;
        // for(auto i:right) cout<<i<<" ";
        
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(left[i]>=times&&right[i]>=times) ans.push_back(i);
        }

        return ans;
    }
};