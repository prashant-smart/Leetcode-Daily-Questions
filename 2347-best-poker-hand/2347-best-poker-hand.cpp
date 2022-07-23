class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        
        bool isvalid=1;
        for(int i=1;i<suits.size();i++){
            if(suits[i]!=suits[i-1]){
                isvalid=0;
                break;
            }
        }
        if(isvalid)
            return  "Flush";
        
        bool isTwo=0;
        
        for(int i=0;i<ranks.size();i++){
            int cnt=1;
            for(int j=i+1;j<ranks.size();j++){
                if(ranks[j]==ranks[i]){
                    cnt++;
                }
            }
            if(cnt==3) return "Three of a Kind";
            if(cnt==2) isTwo=1;
        }
        if(isTwo) return "Pair";
        
        return "High Card";
    }
};