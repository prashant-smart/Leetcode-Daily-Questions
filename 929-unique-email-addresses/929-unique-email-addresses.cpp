class Solution {
public:
    
    string filterString(string & s){
        string validEmail;
        bool isDomain=0;
        for(int i=0;i<s.length();i++){
            
            if(!isDomain&&s[i]=='.'){
                continue;
            }
            
            if(!isDomain&&s[i]=='+'){
                while(s[i]!='@'){
                    i++;
                }
            }
            
            if(s[i]=='@') isDomain=1;
            
            validEmail.push_back(s[i]);
        }
        return validEmail;
    }
    
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        for(auto email:emails){
            st.insert(filterString(email));
        }
        return st.size();
    }
    
};