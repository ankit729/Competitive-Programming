// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

// Implement the LRUCache class:

// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
// Follow up:
// Could you do get and put in O(1) time complexity?

 

// Example 1:

// Input
// ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// Output
// [null, null, null, 1, null, -1, null, -1, 3, 4]

// Explanation
// LRUCache lRUCache = new LRUCache(2);
// lRUCache.put(1, 1); // cache is {1=1}
// lRUCache.put(2, 2); // cache is {1=1, 2=2}
// lRUCache.get(1);    // return 1
// lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
// lRUCache.get(2);    // returns -1 (not found)
// lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
// lRUCache.get(1);    // return -1 (not found)
// lRUCache.get(3);    // return 3
// lRUCache.get(4);    // return 4
 

// Constraints:

// 1 <= capacity <= 3000
// 0 <= key <= 3000
// 0 <= value <= 10^4
// At most 3 * 10^4 calls will be made to get and put.

class LRUCache {
    typedef list<pair<int,int>> LI;
    typedef unordered_map<int,LI::iterator> MPLI;
    LI used;
    MPLI cache;
    int cap;
public:
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        auto it=cache.find(key);
        if(it==cache.end())
            return -1;
        touch(it);
        return used.front().second;
    }
    
    void put(int key, int value) {
        auto it=cache.find(key);
        if(it==cache.end()){
            if(cache.size()==cap){
                cache.erase(used.back().first);
                used.pop_back();
            }
            used.push_front({key,value});
        }
        else{
            touch(it);
            used.front().second=value;
        }
        cache[key]=used.begin();
    }
private:
    void touch(MPLI::iterator it) {
        int key=it->first,val=it->second->second;
        used.erase(it->second);
        used.push_front({key,val});
        it->second=used.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
