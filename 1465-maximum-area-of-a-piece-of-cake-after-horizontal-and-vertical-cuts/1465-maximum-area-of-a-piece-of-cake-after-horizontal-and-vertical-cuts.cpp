class Solution {
public:
    
    int findMaxDis(int size,vector<int>& vec){
        int high=1;
         int len=vec[0]-0;
        while(high<vec.size()){
            len=max(len,vec[high]-vec[high-1]);
            high++;
        }
        len=max(len,size-vec[high-1]);
        return len;
    }
    
    
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        unsigned long long l1=0,l2=0;
        l1=findMaxDis(h,horizontalCuts);
        l2=findMaxDis(w,verticalCuts);
        
        unsigned long long area=(l1%(1000000000+7)*l2%(1000000000+7))%(1000000000+7);
        return area;
      
    }
};