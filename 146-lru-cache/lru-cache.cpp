class LRUCache {
public:

    int capacity;
    list<pair<int,int>> cache;
    unordered_map<int,list<pair<int,int>>::iterator> cacheMap;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cacheMap.find(key) == cacheMap.end()) return -1;

        auto it = cacheMap[key];
        int value = it->second;
        cache.erase(it);
        cache.push_front({key,value});
        cacheMap[key] = cache.begin();
        return value;
    }
    
    void put(int key, int value) {
        if(cacheMap.find(key) == cacheMap.end()){
            if(cache.size() == this->capacity){
                auto lru = cache.back();
                cache.pop_back();
                cacheMap.erase(lru.first);
            }
            cache.push_front({key,value});
            cacheMap[key] = cache.begin();
        }else{
            auto it = cacheMap[key];
            cache.erase(it);
            cache.push_front({key,value});
            cacheMap[key] = cache.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */