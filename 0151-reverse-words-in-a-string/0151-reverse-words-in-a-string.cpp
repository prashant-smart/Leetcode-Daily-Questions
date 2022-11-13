class Solution {
public:
    string reverseWords(string s) {
        reverse(begin(s),end(s));
        int prevIdx=0;
        for(int i=0;i<s.length();i++){
            
            if(i!=0&&s[i]!=' '&&s[i-1]==' '){
                prevIdx=i;
            }
            
            if(s[i]==' '){
                if(prevIdx<i){
                    reverse(begin(s)+prevIdx,begin(s)+i);
                }
                prevIdx=i;
            }
            
            
        }
        if(s.back()!=' ')
            reverse(begin(s)+prevIdx,end(s));
        else {
            while(s.size()&&s.back()==' ') s.pop_back();
        }
        
        string ans;
        for(auto i:s){
            if(i==' '){
                if(ans.size()&&ans.back()!=' ') ans.push_back(i); 
            }else ans.push_back(i);
        }
        return ans;
    }
};