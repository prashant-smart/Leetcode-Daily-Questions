class Solution {
public:
 string minWindow(string s, string t)
{
    if(s.length()<t.length() || t=="" || s=="")
         return "";   
     unordered_map<char, int> umap;
    for (auto iter : t)
        umap[iter]++;
    int count = umap.size();
    int maxLeft = 0, maxRight = INT_MAX - 1;
    int low = 0, high = -1;
    while(low<(int)s.length()&& high<(int)s.length()){
        if(count){
            high++;
            if(umap.count(s[high])){
                umap[s[high]]--;
                if(umap[s[high]]==0)
                    count--;
            }
            
        }
        else{
        // cout<<s.substr(low,high-low+1)<<endl;
            if((high-low+1)<(maxRight-maxLeft+1)){
                    maxRight=high;
                    maxLeft=low;
                }
            if(umap.count(s[low]))
                {
                    umap[s[low]]++;
                    if(umap[s[low]]==1){
                        count++;
                    }
                    
                }
                low++;
            while((!umap.count(s[low]) || umap[s[low]]<0)&& low<=high){
                if(umap.count(s[low]))
                {
                    umap[s[low]]++;
                    if(umap[s[low]]==1){
                        count++;
                    }
                    
                }
                low++;
            }
        }
    }
        if(maxRight==INT_MAX-1)
            return "";
       return s.substr(maxLeft,maxRight-maxLeft+1);
}
};