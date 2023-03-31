class Solution {
public:
    string helper(vector<string> &temp,int maxWidth){
        int cnt=0;
        for(auto i:temp) cnt+=i.length();
        
        int diff=maxWidth-cnt;
        int mul=(temp.size()-1)==0?0:diff/(temp.size()-1);
        int left=(temp.size()-1)==0?0:diff%(temp.size()-1);
        
        string ans;
        for(auto i:temp){
            ans+=i;
            for(int j=1;j<=mul;j++){
                ans.push_back(' ');
            }
            if(left){
                ans.push_back(' ');
                left--;
            }
        }
        while(ans.length()>maxWidth){
            ans.pop_back();
        }
             while(temp.size()==1&&ans.length()<maxWidth)
                        ans.push_back(' ');
        while(temp.size()) temp.pop_back();
        return ans;
        
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int cnt=0;
        vector<string> temp; 
        for(int i=0;i<words.size();i++){
            cnt+=words[i].length();
            if(temp.size())
                cnt++;
            // cout<<words[i]<< " "<<cnt<<endl;
            if(cnt<=maxWidth){
                temp.push_back(words[i]);
                
                if(i==words.size()-1){
                    string s;
                    for(auto i:temp){
                        s+=i;
                        s.push_back(' ');
                    }
                    if(s.back()==' ') s.pop_back();
                    
                    while(s.length()<maxWidth)
                        s.push_back(' ');
                    ans.push_back(s);
                }
            }
            else{
                ans.push_back(helper(temp,maxWidth));
                cnt=0;
                i--;
                
            }
        }
        return ans;
    }
};