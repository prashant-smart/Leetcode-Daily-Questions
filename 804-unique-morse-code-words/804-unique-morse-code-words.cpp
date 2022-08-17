class Solution {
public:
    
    string helper(string &s,int i,vector<string> &alphabets_code){
        if(i==s.length()) return "";
        return alphabets_code[s[i]-'a']+helper(s,i+1,alphabets_code);
    }
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> alphabets_code={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> st;
        for(auto i:words){
            st.insert(helper(i,0,alphabets_code));
        }
        return st.size();
    };
    
    
};