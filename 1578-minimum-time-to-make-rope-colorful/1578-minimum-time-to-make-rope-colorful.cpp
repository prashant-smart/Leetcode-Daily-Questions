class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        char current_color=colors[0];
        int ans=0;
        int prev_idx=0;
        for(int i=1;i<colors.length();i++){
            if(colors[i]!=current_color){
                current_color=colors[i];
                prev_idx=i;
            }else{
                if(neededTime[i]>=neededTime[prev_idx]){
                    current_color=colors[i];
                    ans+=neededTime[prev_idx];
                    prev_idx=i;
                }else{ 
                    ans+=neededTime[i];
                     
                }
            }
            // cout<<ans<<" "<<current_color<<endl;
        }
        return ans;
    }
};