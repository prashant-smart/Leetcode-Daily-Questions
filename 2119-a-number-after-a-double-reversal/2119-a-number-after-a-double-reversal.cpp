class Solution {
public:
    bool isSameAfterReversals(int num) {
        string s1=to_string(num);
        
    
        reverse(begin(s1),end(s1));
        int  s2=stol(s1);
        s1=to_string(s2);
        reverse(begin(s1),end(s1));
        // cout<<s2<<" "<<s1<<endl;
        if(stol(s1)==num) return 1;
        return 0;
    }
};