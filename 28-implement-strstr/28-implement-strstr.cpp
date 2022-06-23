class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle=="") return 0;
        int arr[needle.length()];
        arr[0]=0;
        int f=0,l=1;
        while(l<needle.length()){
            if(needle[l]==needle[f])
                arr[l++]=++f;
            else{
                if(f==0)
                   arr[l++]=0;
                else f=arr[arr[f-1]];
            }
        }
        // for(auto &i:arr) i--;
        //Algo
        int j=0,i=0;
        
        while(j<haystack.length()){
            if(needle[i]==haystack[j]){
                i++,j++;
            }else{
                if(i==0) j++;
                else {
                    cout<<i<<" ";
                    i=arr[i-1];
                }
            }
            // cout<<i<<" "<<j<<endl;
            if(i==needle.length()) return j-needle.length();
        }
       return -1;
    }
  
};