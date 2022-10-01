class Solution {
public:
    unordered_map<string,int> memo;
    int helper(string s,unordered_map<string,int>& umap,int n,string prev){
        if(prev!="" && !umap.count(prev))
            return 0;
        if(n==s.length())
            return 1;
        else if(n>s.length())
            return 0;
        if(memo.count(to_string(n)))
            return memo[to_string(n)];
        string next="";
        int a=0,b=0;
        if(n+1<s.length()){
            a=helper(s,umap,n+2,next+s[n]+s[n+1]);
        }
        b=helper(s,umap,n+1,next+s[n]);
        return memo[to_string(n)]=a+b;
        
    }
    
    int numDecodings(string s) {
        unordered_map<string,int> umap;
        for(int i=1;i<=26;i++){
            umap[to_string(i)]++;
        }
        if(s[0]=='0')
            return 0;
        return helper(s,umap,0,"");
        
    }
};