class Solution {
public:
    string breakPalindrome(string s) {
        if(s.length()<=1) return "";
        vector<string> vec;
        string k=s;
        for(int i=0;i<s.length();i++){
            for(char a='a';a<='z';a++){
                if(a==s[i]||(i==(s.length()/2)&&s.length()%2!=0)) continue;
                s[i]=a;
                vec.push_back(s);
                s=k;
            }
        }
        sort(begin(vec),end(vec));
        return vec[0];
        
    }
};