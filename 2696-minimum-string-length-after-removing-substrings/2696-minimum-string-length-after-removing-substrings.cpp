class Solution {
public:
    
    int minLength(string s) {
       stack<char> st;
        int ans=0;
        for(auto i:s){
            if((i=='B'&&st.size()&&st.top()=='A')||(i=='D'&&st.size()&&st.top()=='C')){
                st.pop();
                ans++;
                continue;
            }else st.push(i);
            
        }
        return st.size();
    }
};