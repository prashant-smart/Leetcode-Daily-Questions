class MyCalendar {
public:
    set<pair<int,int>> st;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
       for(auto i:st){
           // if(start==13)
           //     cout<<i.first<<" "<<i.second<<endl; 
           if(i.first<=start&&i.second>=start||i.first<=end-1&&i.second>=end-1||i.first>=start&&i.first<=end-1||i.second>=start&&i.second<=end-1){
               
                                          
                return 0;
           }
       } 
        st.insert({start,end-1});
        return 1;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

// ["MyCalendar","book","book","book","book","book","book","book","book","book","book"]
// [[],[47,50],[33,41],[39,45],[33,42],[25,32],[26,35],[19,25],[3,8],[8,13],[18,27]]