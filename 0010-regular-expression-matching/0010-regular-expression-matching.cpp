class Solution {
public:
    int dp[21][21];
    bool helper(string& s,string &p,int i,int j){
        if(i<0||j<0){
            if(i<0&&j<0){
                return 1;
            }
            if(j>0&&p[j]=='*'){
                return helper(s,p,i,j-2);
            }else return 0;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
        bool ans=0;
        if(p[j]=='.'){
            ans|=helper(s,p,i-1,j-1);
        }else if(p[j]=='*'){
                if(s[i]==p[j-1]||p[j-1]=='.'){
                    ans|=helper(s,p,i-1,j)|helper(s,p,i-1,j-2);
                }
         
            ans|=helper(s,p,i,j-2);
        }else if(p[j]==s[i]){
            ans|=helper(s,p,i-1,j-1);
        }else ans= 0;
        return dp[i][j]=ans;
    }
    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof dp);
        return helper(s,p,s.length()-1,p.length()-1);
    }
};