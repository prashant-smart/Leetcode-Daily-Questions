class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<long ,long> count_l,count_r, countL,countR,sumL,sumR,left,right;
        unordered_map<int,pair<int,int>> start;
        
        for(int i=0;i<arr.size();i++){
            countL[i]=count_l[arr[i]];
            count_l[arr[i]]++;
            
            left[i]=sumL[arr[i]];
            sumL[arr[i]]+=i;
            
            if(!start.count(arr[i])){
                start[arr[i]]={i,i};
            }else start[arr[i]].second=i;
        }
        for(int i=arr.size()-1;i>=0;i--){
            countR[i]=count_r[arr[i]];
            count_r[arr[i]]++;
            
            right[i]=sumR[arr[i]];
            sumR[arr[i]]+=i;
        }
        
        
        vector<long long> ans;
        for(int i=0;i<arr.size();i++){
            long long l=0,r=0;
            
            if(start[arr[i]].first!=i){
                l=abs(i*countL[i]-left[i]);
            }
            if(start[arr[i]].second!=i){
                r=abs(right[i]-i*countR[i]);
            }
            
            ans.push_back(l+r);
            
        }
        return ans;
    }
};