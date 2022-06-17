class Solution {
public:
    #define ll long long 
    #define lld long double 
    #define ull unsigned long long #define pb push_back 
    #define ff(n) for (auto iter : n)            
    #define pinf LONG_LONG_MAX #define ninf LONG_LONG_MIN 
    #define all(x) x.begin(), x.end() 
    //sort(all(v));
    #define rall(x) x.rbegin(), x.rend()
    
    long long getDescentPeriods(vector<int>& p) {
        ll ans=0;
        ll cnt=1;
        int i;
        for( i=0;i<p.size()-1;i++){
            if(p[i]-1==p[i+1]) cnt++;
            else{
                // cout<<i<<" ";
                ans+=cnt*(cnt+1)/2;
                cnt=1;
            }
        }
        if(i!=0){
            if(p[i]+1==p[i-1]){
                ans+=cnt*(cnt+1)/2;
            }else ans++;
        }else ans++;
        return ans;
        
    }
};