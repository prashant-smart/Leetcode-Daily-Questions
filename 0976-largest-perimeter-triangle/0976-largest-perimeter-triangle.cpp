class Solution {
public:
    
    int largestPerimeter(vector<int>& vec) {
        sort(begin(vec),end(vec));
        
        
        int a=vec.back();
        vec.pop_back();
        int b=vec.back();
        vec.pop_back();
        int c=vec.back();
        vec.pop_back();
        
        while(1){
            if(a+b+c<=2*a){
                if(vec.size()==0) return 0;
                a=vec.back();
                vec.pop_back();
                
            }else if(a+b+c<=2*b){
                if(vec.size()==0) return 0;
                b=vec.back();
                vec.pop_back();
                
            }else if(a+b+c<=2*c){
                if(vec.size()==0) return 0;
                c=vec.back();
                vec.pop_back();
                
            }else return a+b+c;
            
        }
        return 0;
        
    }
};