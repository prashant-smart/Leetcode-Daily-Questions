class Solution {
public:
    string pushDominoes(string d) {
        string ans;
        for(auto i:d) ans.push_back('.');
        
        int l=0;
        while(l<d.length()){
            if(d[l]!='.'){
                if(d[l]=='L'){
                     int k=l;
                    while(l>=0&&ans[l]=='.'){
                            ans[l--]='L';
                    }
                    l=k+1;
                    continue;
                }
                
                int i;
                for( i=l+1;i<d.length()&&d[i]=='.';i++){
                    // do nothing eat five star    
                }
                if(i==d.length()){
                    if(d[l]=='R'){
                        while(l<d.length()&&ans[l]=='.'){
                            ans[l++]='R';
                        }
                    }else{
                        while(l>=0&&ans[l]=='.'){
                            ans[l--]='L';
                        }
                    }
                    l=i;
                }
                else{
                    int k=i;
                    if(d[l]!=d[i]&&d[l]=='R'){
                        
                            while(l<i){
                                ans[l++]='R';
                                ans[i--]='L';
                            }
                        l=k+1;
                        
                    }else{
                        while(l<i){
                            ans[l++]='R';
                        }
                    }
                    
                }
            }else l++;
            
        }
        return ans;
    }
};