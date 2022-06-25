class Solution {
public:
    int nthUglyNumber(int n) {
        unordered_map<int,int> umap;
        priority_queue<int,vector<int>,greater<int>> que;
        que.push(1);
        long long ans;
        while(n--){
            ans=que.top();
            que.pop();
            if(umap.count(ans)){
                n++;
                continue;
            }
            // cout<<ans<<" ";
            
            if(ans*2<INT_MAX)
                que.push(ans*2);
            if(ans*3<INT_MAX)
                que.push(ans*3);
            if(ans*5<INT_MAX)
                que.push(ans*5);
            
            umap[ans]++;
        }
        return ans;
    }
};