class Solution {
public:
    int numSplits(string s) {
        vector<int> left(s.length(),0),right(s.length(),0);
        unordered_set<char> left_set,rihgt_set;
        int cnt=0;
        for(int i=0;i<s.length();i++){
            if(!left_set.count(s[i]))
                left[i]=++cnt;
            else left[i]=cnt;
            left_set.insert(s[i]);
        }
        cnt=0;
        for(int i=s.length()-1;i>=0;i--){
            if(!rihgt_set.count(s[i]))
                right[i]=++cnt;
            else right[i]=cnt;
            rihgt_set.insert(s[i]);
        }
        for(auto i:left)cout<<i<<" ";
        cout<<endl;
        for(auto i:right)cout<<i<<" ";
        cout<<endl;
        
        cnt=0;
        for(int i=0;i<s.length()-1;i++){
            if(left[i]==right[i+1]){
                cnt++;
            }
        }
        return cnt;
    }
};