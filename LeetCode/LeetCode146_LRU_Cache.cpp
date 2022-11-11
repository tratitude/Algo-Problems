// Time complexity: O(1)
// Space complexity: O(n)
class LRUCache {
    int capacity = 0;
    // key -> it
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    // {key, value}
    list<pair<int, int>> cacheList;
public:
    LRUCache(int capacity): capacity(capacity) {

    }
    
    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end())
            return -1;
        
        int value = it->second->second;
        cacheList.erase(it->second);
        cacheList.push_front({key, value});
        mp[key] = cacheList.begin();
        return value;
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        if (it != mp.end()) {
            cacheList.erase(it->second);
        }
        if (cacheList.size() == capacity) {
            mp.erase(cacheList.back().first);
            cacheList.pop_back();
        }
        
        cacheList.push_front({key, value});
        mp[key] = cacheList.begin();
    }
};
// Time complexity: O(1)
// Space complexity: O(n)
class LRUCache {
  using Cache = pair<int, int>;
  using CacheList = list<Cache>;
  // {key, list pointer}
  unordered_map<int, CacheList::iterator> cacheMap;
  // {key, value}
  CacheList cacheList;
  int cap;

  bool isExist(int key) { return cacheMap.count(key) > 0; }
  bool isFull() { return cacheList.size() >= cap; }
  // from map and list
  void removeOldCache() {
    auto cache = cacheList.back();

    // remove from list
    cacheList.pop_back();

    // remove from map
    auto it = cacheMap.find(cache.first);
    cacheMap.erase(it);
  }
  // pop cache from list
  // assume cache must exist
  Cache popCache(int key) {
    auto mpIt = cacheMap.find(key);
    auto it = mpIt->second;
    Cache cache = {it->first, it->second};

    // remove from list
    cacheList.erase(it);

    // remove from map
    cacheMap.erase(mpIt);  // slower but safer

    return cache;
  }
  // push cache on top of list
  // if cache is not exist, create map
  void pushCache(Cache c) {
    // push top of list
    cacheList.push_front(c);

    // update map
    auto it = cacheList.begin();
    cacheMap[c.first] = it;
  }

 public:
  LRUCache(int capacity) { cap = capacity; }

  int get(int key) {
    int ret = -1;
    // check the key is exist, and return value
    if (isExist(key)) {
      auto cache = popCache(key);
      // move {key, value} on top
      pushCache(cache);

      ret = cache.second;
    }
    return ret;
  }

  void put(int key, int value) {
    Cache cache = {key, value};
    if (isExist(key)) popCache(key);

    if (isFull()) removeOldCache();

    pushCache(cache);
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */