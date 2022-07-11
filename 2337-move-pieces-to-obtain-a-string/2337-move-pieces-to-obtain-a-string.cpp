class Solution {
public:
    bool canChange(string start, string target) {
        int r=0;
        int l=0;
        int R=0,L=0;
        
        for(int i=0;i<start.length();i++){
            if(start[i]=='R') r++;
            else if(start[i]=='L'){
               l++;
            }
            if(target[i]=='R') R++;
            else if(target[i]=='L'){
               L++;
            }
        }
        
        if(r!=R||l!=L) return 0;
        r=0,l=0;
        for(int i=0;i<start.length();i++){
            if(start[i]=='R') r++;
            else if(start[i]=='L'){
                if(r) r--;
            }
            
            if(target[i]=='R'){
                if(!r) return 0;
                r--;
            }else if(target[i]=='L'){
                if(r) r--;
            }
        }
        if(r) return 0;
        
        for(int i=start.length()-1;i>=0;i--){
            if(start[i]=='L') l++;
            else if(target[i]=='R'){
                if(l) l--;
            }
            
            if(target[i]=='L'){
                if(!l) return 0;
                l--;
            }else if(target[i]=='R'){
                if(l) l--;
            }
        }
        if(l) return 0;
        return 1;
    }
};