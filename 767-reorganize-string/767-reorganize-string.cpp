class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>> que;
        unordered_map<char,int> umap;
        for(auto i:s) umap[i]++;
        for(auto i:umap){
            que.push({i.second,i.first});
        }
        
        string ans;
        while(que.size()){
            auto fir=que.top();
            que.pop();
            
            if(!que.size()){
                if(fir.first!=1) return "";
                ans.push_back(fir.second);
                continue;
            }
                
                auto sec=que.top();
                que.pop();
                ans.push_back(fir.second);
                ans.push_back(sec.second);
                
                fir.first--,sec.first--;
            
            
            if(fir.first>0) que.push(fir);
            if(sec.first>0) que.push(sec);
        }
        return ans;
    }
};