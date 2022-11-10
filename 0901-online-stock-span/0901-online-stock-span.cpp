class StockSpanner {
    stack<pair<int,int>> s;
public:
    StockSpanner() {
        
    }
    
    int next(int p) {
       int count=0;
        while(s.size()&&s.top().first<=p){
            count++;
            count+=s.top().second;
            s.pop();
        }
       
        s.push({p,count});
        return count+1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */