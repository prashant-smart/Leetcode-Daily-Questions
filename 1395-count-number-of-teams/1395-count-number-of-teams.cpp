class Solution {
public:
    
    int dp1[1001][4];
    int helper1(vector<int>&vec,int i,int k){
        if(k==1){
            return 1;
        }
        
        if(i>=vec.size()) return 0;
        
        if(dp1[i][k]!=-1) return dp1[i][k];
        int ans=0;
        for(int ii=i;ii<vec.size();ii++){
            if(vec[i]<vec[ii]){
                ans+=helper1(vec,ii,k-1);
            }
        }
          dp1[i][k]=ans;
          helper1(vec,i+1,k);
        return ans;
        
    }
    int dp2[1001][4];
    int helper2(vector<int>&vec,int i,int k){
        if(k==1){
            return 1;
        }
        
        if(i>=vec.size()) return 0;
        
        if(dp2[i][k]!=-1) return dp2[i][k];
        int ans=0;
        for(int ii=i;ii<vec.size();ii++){
            if(vec[i]>vec[ii]){
                ans+=helper2(vec,ii,k-1);
            }
        }
        dp2[i][k]=ans;
        helper2(vec,i+1,k);
        
        // cout<<i<<" "<<k<<" "<<ans<<endl;

         return ans;
        
    }
    int numTeams(vector<int>& vec) {
        memset(dp1,-1,sizeof dp1);
        memset(dp2,-1,sizeof dp2);
        helper1(vec,0,3);
        helper2(vec,0,3);
        
        int ans=0;
        for(int i=0;i<vec.size();i++){
            // cout<<dp1[i][3]<<" "<<dp2[i][3]<<" "<<i<<endl;
            if(dp1[i][3]!=-1) ans+=dp1[i][3];
            if(dp2[i][3]!=-1) ans+=dp2[i][3];
        }
        return ans;
    }
};