class Solution {
public:
    string addSpaces(string s, vector<int>& sp) {
        string ans;
        int idx=0;
        for(int i=0;i<s.length();i++){
            while(idx<sp.size()&&sp[idx]==i){
                ans.push_back(' ');
                idx++;
            }
            ans.push_back(s[i]);
            
        }
        return ans;
    }
};