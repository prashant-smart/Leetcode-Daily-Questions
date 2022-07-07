class Solution {
public:
    int countAsterisks(string s) {
        int a=0,b=0;
        bool first=0,second=0;
        for(auto i:s){
            if(i=='|'){
                if(!first) first=1;
                else if(!second) second=1;
            }
            if(i=='*'){
                
                
                if(!first){
                    a++;
                }else if(first&&!second){
                    b++;
                }else if(first&&second){
                    first=0,second=0;
                    b=0;
                }
            }else{
                if(first&&second){
                    first=0,second=0;
                    b=0;
                }
            }
        }
        return a+b;
    }
};