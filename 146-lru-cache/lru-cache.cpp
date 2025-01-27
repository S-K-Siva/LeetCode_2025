class LRUCache {

private: 
    int capacity;
    list<pair<int,int>> cache;
    unordered_map<int,list<pair<int,int>>::iterator> cacheMap;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cacheMap.find(key) == cacheMap.end()) return -1;
        auto it = cacheMap[key];
        int result = it->second;
        cache.erase(it);
        cache.push_front({key,result});
        cacheMap[key] = cache.begin();
        return result;
    }
    
    void put(int key, int value) {
        if(cacheMap.find(key) != cacheMap.end()){
            auto it = cacheMap[key];
            cache.erase(it);
        }else if(cache.size() == this->capacity){
            pair<int,int> leastUsed = cache.back();
            cacheMap.erase(leastUsed.first);  
            cache.pop_back();
        }
        cache.push_front({key,value});
        cacheMap[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */