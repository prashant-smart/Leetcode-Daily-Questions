class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals),end(intervals));
        int i=0,j=1;
        int cnt=0;
        while(j<intervals.size()){
            if(intervals[i][1]<=intervals[j][0]){
                i=j;
                j++;
            }else if(intervals[i][1]<=intervals[j][1]){
                cnt++;
                j++;
            }else if(intervals[i][1]>intervals[j][1]){
                cnt++;
                i=j;
                j++;
            }
        }
        return cnt;
    }
};