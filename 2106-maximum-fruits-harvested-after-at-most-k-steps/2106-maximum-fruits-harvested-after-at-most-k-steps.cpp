class Solution {
public:
    int helper(vector<int> &left,vector<int>& right,int val,int k){
        int i=1;
        int mx=0;
        while(1){
            if(i*2<k){
               mx=max({mx,val+left[i-1]+right[k-i*2-1]}); 
            }else break;
            i++;
        }
        return mx;
    }
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        unordered_map<int,int> value;
        for(auto i:fruits) value[i[0]]=i[1];
        
        vector<int> left(k,0),right(k,0);
        int i=startPos-1,idx=0;
        
        while(idx<k){
            if(i==startPos-1) left[idx++]=value[i--];
            else{
                left[idx]+=value[i]+left[idx-1];
                i--;
                idx++;
            }
        }
        
        i=startPos+1,idx=0;
        
        while(idx<k){
            
            if(i==startPos+1) right[idx++]=value[i++];
            else{
                right[idx]+=value[i]+right[idx-1];
                i++;
                idx++;
            }
        }
        int mx=(k!=0)?max(left[k-1],right[k-1]):0;
        mx+=value[startPos];
        return max({mx,helper(left,right,value[startPos],k),helper(right,left,value[startPos],k)});
        
        
        
    }
};