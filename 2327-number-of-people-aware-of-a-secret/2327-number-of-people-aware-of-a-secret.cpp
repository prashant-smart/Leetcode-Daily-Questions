class Solution {
public:
    int MOD=1000000007;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        list<pair<int,int>> lst;
        lst.push_back({1,1});
        long long int size=1;
        int s=1;
        for(int i=1;i<=n;i++){
            while(s&& i-lst.front().second>=forget){
                size-=lst.front().first;
                s--;
                lst.pop_front();
                
            }
            
            long long int cnt=0;
            for(auto ii:lst){
                if(i==5){
                }
                if(i-ii.second>=delay) cnt+=ii.first;
                else break;
                cnt%=MOD;
            }
            
            if(cnt>0){
                size=(size+cnt);
                
                lst.push_back({cnt,i});
                s++;
            }
            
        }
        return size%MOD;
    }
};