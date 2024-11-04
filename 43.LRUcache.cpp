class LRUCache {
private:
    int maxCapacity;
    list<pair<int, int>> lruList;  // Stores (key, value) pairs
    unordered_map<int, list<pair<int, int>>::iterator> cache;  // Maps key to its position in the list

public:
    LRUCache(int capacity) {
        this->maxCapacity = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;  // Key not found
        }
        // Move the accessed (key, value) to the front of the list (most recently used)
        lruList.splice(lruList.begin(), lruList, cache[key]);
        return cache[key]->second;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // If key exists, update value and move it to the front of the list
            cache[key]->second = value;
            lruList.splice(lruList.begin(), lruList, cache[key]);
        } else {
            // If the cache is full, remove the least recently used item (back of the list)
            if (lruList.size() == maxCapacity) {
                int lruKey = lruList.back().first;
                lruList.pop_back();
                cache.erase(lruKey);
            }
            // Insert the new (key, value) at the front of the list
            lruList.emplace_front(key, value);
            cache[key] = lruList.begin();
        }
    }
};
