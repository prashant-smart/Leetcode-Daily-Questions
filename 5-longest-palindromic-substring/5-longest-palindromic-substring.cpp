class Solution {
public:
    
 string longestPalindrome(string s) {
        int end=1; int start=0;
        for(int i=1; i<s.length();i++){
            
            //even logic
            int h=i-1,l=i;
            while(i>=0 && l<s.length()&& s[h]==s[l]){
                if(h-l+1>end){
                    end=h-l+1;
                    start=l;
                }
                h++;
                l--;
            }
            
            //odd logic
             h=i-1,l=i+1;
            while(i>=0 && l<s.length()&& s[h]==s[l]){
                if(h-l+1>end){
                    end=h-l+1;
                    start=l;
                }
                h++;
                l--;
            }
            
        }
        return s.substr(start,end);
        
    }
};