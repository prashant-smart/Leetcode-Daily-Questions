class LRUCache {
public:
    list <int> l;
    unordered_map<int,int> keyVal;
    unordered_map<int,list<int>::iterator> address;
    int cap;
    int size;
    LRUCache(int capacity) {
        size=0;
        cap=capacity;
    }
    
    int get(int key) {
        if(!keyVal.count(key)) return -1;
        
        list<int>:: iterator it=address[key];
        l.erase(it);
        l.push_front(key);
        address[key]=l.begin();
        return keyVal[key];
    }
    
    void put(int key, int value) {
        if(cap==size&&!keyVal.count(key)){
            int k=l.back();
            address.erase(k);
            l.pop_back();
            keyVal.erase(k);
            size--;
        }
        if(!keyVal.count(key)){
            size++;
            l.push_front(key);
            address[key]=l.begin();
        }
        get(key);
        keyVal[key]=value;
        
    }
};

/*
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
*/