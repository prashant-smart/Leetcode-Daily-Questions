class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        for(char c:s){
            if(st.size()&&c==st.top().first && st.top().second+1==k){
                st.pop();
            }
            else if(st.size()  && c==st.top().first){
                st.top().second++;
            }
            else if(st.empty() || c!=st.top().first){
                st.push({c,1});
            }
        }
        string ans="";
        while(st.size()){
            ans.append(st.top().second,st.top().first);st.pop();
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};