class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (cacheMap.find(key) == cacheMap.cend())
            return -1;
        
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        cacheMap[key] = cacheList.begin();
        return cacheList.begin()->value;
    }
    
    void put(int key, int value) {
        if (cacheMap.find(key) == cacheMap.cend()) {
            if (cacheList.size() == capacity) {
                cacheMap.erase(cacheList.back().key);
                cacheList.pop_back();
            }
            cacheList.push_front(CacheNode(key, value));
            cacheMap[key] = cacheList.begin();
        } else {
            cacheMap[key]->value = value;
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            cacheMap[key] = cacheList.begin();
        }
    }

private:
    struct CacheNode {
        int key;
        int value;
        CacheNode(int k, int v) :key(k), value(v) {}
    };
    list<CacheNode> cacheList;
    unordered_map<int, list<CacheNode>::iterator> cacheMap;
    int capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
