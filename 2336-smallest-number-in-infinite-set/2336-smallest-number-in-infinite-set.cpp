class SmallestInfiniteSet {
public:
    unordered_set<int> s;
    priority_queue<int, vector<int>, greater<int>> pq;
    int count=1;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        int small=(pq.size())?pq.top():count++;
        // cout<<small<<" ";
        
        if(pq.size())
            pq.pop();
        if(s.count(small))
            s.erase(small);
        return small;
    }
    
    void addBack(int num) {
        if(!s.count(num)&num<count){
            pq.push(num);
            s.insert(num);
        }
        
        
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */