class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        for(auto i:amount) if(i)pq.push(i);
        
        int days=0;
        int isvalid;
        while(pq.size()){
            isvalid=0;
            int val=pq.top();
            pq.pop();
            if(val){
                val--;
            }
            int val2=0;
            if(pq.size()){
                 val2=pq.top();
                pq.pop();
                if(val2){
                    val2--;
                }
                
            }
            if(val){
                pq.push(val);
                isvalid++;
            }
            if(val2){
                pq.push(val2);
                isvalid++;
            }
            // if(val2||val)
            // if(isvalid>0)
                days++;
        }
        return days;
    }
};