class Solution {
public:
    
    int dp[4005];
    void KMP(string &str,vector<int> &k){
        int i=0,j=1;
        k[0]=0;
        while(j<str.length()){
            if(str[i]==str[j]){
                k[j]=i+1;
                j++;
                i++;
            }else{
                if(i==0){
                    k[j++]=0;
                }else{
                    i=k[i-1]==0?0:k[i-1]-1;
                }
            }
        }
    }
    
    int solve(string &s,int i){
       
        if(i==s.length()) return 0;
        if(dp[i]!=-1) return dp[i];
        
        string str;
        for(int j=i;j<s.length();j++){
            str.push_back(s[j]);
        }
        
        vector<int> k(str.length());
        
        KMP(str,k);
        int ans=1;
        for(int j=0;j<k.size();j++){
            if(j+1==k[j]*2){
                ans=max(ans,1+solve(s,i+k[j]));
            }
        }
        return dp[i]=ans;
        
    }
    int deleteString(string s) {
        memset(dp,-1,sizeof dp);
        
        return solve(s,0);
    }
};