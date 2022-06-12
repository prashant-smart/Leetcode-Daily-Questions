class Solution {
public:
    double calculateTax(vector<vector<int>>& b, int in) {
        if(in==0) return 0.00000;
        double sum=0.0;
        for(int i=0;i<b.size();i++){
            b[i][0]=min(b[i][0],in);
            if(i==0){
                sum+=(double)((b[i][0])*b[i][1])/100.0;
            }else sum+=double((b[i][0]-b[i-1][0])*b[i][1])/100.0;
            if(b[i][0]>in) break;
        }
        
        return sum;
    }
};