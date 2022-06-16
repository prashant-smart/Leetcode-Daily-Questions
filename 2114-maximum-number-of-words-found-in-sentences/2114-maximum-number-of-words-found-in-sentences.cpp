class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        unordered_map<string,int> umap;
        int ans=0;
        for(auto i:sentences){
            int k=0;
            string prev;
            int cnt=0;
            while(k<i.length()){
                if(i[k]==' '){
                    if(prev.length()>0)
                        cnt++;
                    prev.clear();
                }else prev.push_back(i[k]);
                
                k++;
            }
           if(prev.length())
               cnt++;
            ans=max(ans,cnt);
        }
        return ans;
    }
};