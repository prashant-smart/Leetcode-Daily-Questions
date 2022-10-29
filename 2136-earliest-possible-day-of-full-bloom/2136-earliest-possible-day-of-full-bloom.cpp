class Solution {
public:
   
    int earliestFullBloom(vector<int>& p, vector<int>& g) {
        int n=p.size();
        vector<pair<long long ,long long >>vec(n);
        for(int i=0;i<n;i++){
            vec[i]={g[i],p[i]};
        }
        
        sort(vec.begin(),vec.end());
        reverse(vec.begin(),vec.end());
        long long  mx=INT_MIN;
        int count=0;
        for(auto iter:vec){
            count+=iter.second;
            mx=max(mx-iter.second,iter.first);
        }
        cout<<mx<< " ";
        return count+mx;
    }
};