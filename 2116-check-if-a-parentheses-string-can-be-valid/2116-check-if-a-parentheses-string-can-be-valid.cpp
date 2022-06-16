class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.length()%2!=0) return 0;
        int bal=0,cnt_unL=0;
        for(int i=0;i<s.length();i++){
            if(locked[i]=='0')cnt_unL++;
            else{
                if(s[i]=='(') bal++;
                else bal--;
            }
            if(bal+cnt_unL<0) return 0;
        }
        cnt_unL=bal=0;
        for(int i=s.length()-1;i>=0;i--){
            if(locked[i]=='0')cnt_unL++;
            else{
                if(s[i]==')') bal++;
                else bal--;
            }
            if(bal+cnt_unL<0) return 0;
        }
        return 1;
    }
};