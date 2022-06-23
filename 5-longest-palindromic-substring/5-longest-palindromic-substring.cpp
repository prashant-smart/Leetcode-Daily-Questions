class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int dp[n+1][n+1];
         memset(dp,0,sizeof(dp));
         int I=0,J=0;
        for(int i=0;i<s.length();i++){
            dp[i][i]=1;
            if(i!=s.length()-1&&s[i]==s[i+1]){
                dp[i][i+1]=1;
                I=i;
                J=i+1;
            }
        }
        
       
        
        for(int i=n-3;i>=0;i--){
            for(int j=i+2;j<n;j++){
                if(dp[i+1][j-1]&&s[i]==s[j]){
                    // cout<<i<<" "<<j<<" "<<I<<" "<<J<<endl;
                    dp[i][j]=1;
                    if(j-i+1>J-I+1){
                        J=j;
                        I=i;
                    }
                }
            }
        }
        return s.substr(I,J-I+1);
    }
};