class Solution {
public:
    bool checkString(string s) {
        string k=s;
        sort(s.begin(),s.end());
        
        for(int i=0;i<s.length();i++){
                if(s[i]!=k[i]) return 0;
        }
        return 1;
    }
};