class Solution {
public:
    bool check(int i,int j,int n){
        if(i<0||j<0||i>=n||j>=n) return 0;
        return 1;
    }
    
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> ans;
        
        
        for(int i=s.length()-1;i>=0;i--){
            int x=startPos[0];
            int y=startPos[1];
            int cnt=0;
            for(int j=i;j<s.length();j++){
                if(s[j]=='U')
                    x--;
                else if(s[j]=='D')
                    x++;
                else if(s[j]=='R')
                    y++;
                else y--;
                if(check(x,y,n)){
                    cnt++;
                }else break;
            }
            
            ans.push_back(cnt);
            
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};