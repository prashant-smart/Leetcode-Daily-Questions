class Solution {
public:
    bool strongPasswordCheckerII(string pass) {
        vector<char> vec={'!','@','#','$','%','^','&','*','(',')','-','+'};
        unordered_map<char,int> sy;
        for(auto i:vec) sy[i]++;
        if(pass.length()<8) return 0;
        
        vector<char> n={'0','1','2','3','4','5','6','7','8','9'};
        unordered_map<char,int> num;
        for(auto i:n) num[i]++;
        
        int l=0,u=0,s=0,nn=0;
        for(int i=0;i<pass.length();i++){
            if(sy.count(pass[i])){
                s++;
            }else if(num.count(pass[i])){
                nn++;
            }else if(pass[i]>=97&&pass[i]<=122){
                l++;
            }else if(pass[i]>=65&&pass[i]<=90){
                u++;
            }
            if(i!=0){
                if(pass[i]==pass[i-1]) return 0;
            }
        }
        return (l&&u&&nn&&s);
    }
};