class Solution {
public:
    int partitionString(string s) {
        int l=0,h=0;
        unordered_set<char> st;
        int cnt=0;
        while(h<s.length()){
            if(st.count(s[h])){
                while(l<h){
                    st.erase(s[l]);
                    l++;
                }
                cnt++;
                
            }
            if(!st.count(s[h])&&h==s.length()-1){
                    cnt++;
            }
            st.insert(s[h]);
            h++;
            
        }
        
            return cnt;
        
    }
};