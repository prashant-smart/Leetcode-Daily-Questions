class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        else if(abs(n)==1) return n<0?1/x:x;
        
        double val=myPow(x,n/2);
        
        if(abs(n)%2==0){
            
            return val*val;
        }
        
        return (n<0)?((1/x)*val*val):x*val*val;
    }
};