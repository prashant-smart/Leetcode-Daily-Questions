class Solution {
public:
    bool helper(string &s,int i,int sum,int &n){
        if(i>=s.length()) return sum==n;
        
        int num=s[i]-'0';
        
        bool ispos=0;
        for(int ii=i+1;ii<=s.length();ii++){
            ispos|=helper(s,ii,num+sum,n);
            if(ii<s.length())
                num=num*10+s[ii]-'0';
        }
        
        return ispos;
        
    }
    int punishmentNumber(int n) {
        int sum=0;
        for(int i=1;i<=n;i++){
            int num=i*i;
            string str=to_string(num);
            
            if(helper(str,0,0,i)){
                
                sum+=num;
            }
            
        }
     
        return sum;
    }
};