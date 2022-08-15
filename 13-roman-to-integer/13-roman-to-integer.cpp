class Solution {
public:
  int roman(string a){
        
            if (a=="I") return 1;
            else if (a=="IV")return 4;
            else if (a=="V")return 5;
            else if (a=="IX")return 9;
            else if (a=="X")return 10;
            else if (a=="XL")return 40;
            else if (a=="L")return 50;
            else if (a=="XC")return 90;
            else if (a=="C")return 100;
            else if (a=="CD") return 400;
            else if (a=="CM")return 900;
            else if (a=="D")return 500;
            else if (a=="M")return 1000;
            else return -1;
            
        
    }
    int check(char a,char b){
        int A=0,B=0,result=0;
        if(b!='0'){
            string s="";
            s+=a;
            s+=b;
            result=roman(s);
            // cout<<s<<" ";
            if(result==-1){
                s="";
                s+=a;
                // cout<<a<<" ";
               A=roman(s);
               s="";
               s+=b;
                B=roman(s);
                // cout<<s<<" ";
                result=A+B;
            }
            return result;
        }
        else{
            string s="";
            s+=a;
            result=roman(s);
            return result;
        }
    }
    int priority(char a, char b){
        string s="";
        s+=a;
        s+=b;
        if(s=="CM"||s=="CD"||s=="XC"||s=="XL"||s=="IX"||s=="IV"){
            return 1;
        }
        return 0;
    }
    int romanToInt(string s) {
        int res=0;
        for(int i=s.length()-1;i>=0;i--){
            if((i-1)>=0&&priority(s[i-1],s[i])){
                res+=check(s[i-1],s[i]);
                --i;
            }
            else{
                res+=check(s[i],'0');
            }
        }
        return res;
    }
};