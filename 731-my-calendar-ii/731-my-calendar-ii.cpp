class MyCalendarTwo {
public:
    map<int,int> mp;
    
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int cnt=0;
        for(auto i: mp){
            cnt+=i.second;
            if(cnt>2){
                mp[start]--;
                mp[end]++;
                return 0;
            }
            
        }
        return 1;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */