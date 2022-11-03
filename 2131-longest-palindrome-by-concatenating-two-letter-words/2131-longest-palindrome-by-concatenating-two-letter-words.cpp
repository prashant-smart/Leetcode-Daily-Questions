class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> umap;
        
        for(auto iter:words){
            umap[iter]++;
        }
        int odd=0;
        int ans=0;
        for(auto iter:words){
            if(umap[iter]==0) continue;
            string k=iter;
            int mn=0;
            reverse(iter.begin(),iter.end());
            int c=umap[k];
            umap.erase(k);
            if(umap.count(iter)){
                mn=min(c,umap[iter]);
                c-=mn;
                umap[iter]-=mn;
                
            }
            ans+=mn*4;
            if(c>0&&iter[0]==iter[1]){
                ans+=((c%2==0)?c:c-1)*2;
                c-=(c%2==0)?c:c-1;
                if(c>0&&!odd)
                    odd+=2;
            
            }
            
        }
        return ans+odd;
    }
};