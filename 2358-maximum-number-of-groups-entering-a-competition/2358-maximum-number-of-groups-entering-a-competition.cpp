class Solution {
public:
    int maximumGroups(vector<int>& g) {
        sort(begin(g),end(g));
        
        
        int cnt=0;
        int prev=1;
        int sum=0;
        int prevSum=0;
        int grp=0;
        for(int i=0;i<g.size();i++){
            cnt++;
            sum+=g[i];
            if(prev==cnt){
                if(sum>prevSum){
                    grp++;
                    prevSum=sum;
                    sum=0;
                    prev++;
                    cnt=0;
                }else{
                    prev++;
                }
            }
        }
        return grp;
    }
};